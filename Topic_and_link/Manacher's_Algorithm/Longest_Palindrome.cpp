/***** Bismillahir Rahmanir Rahim *****/
 
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using oset = tree<T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/// order_of_key(x) returns number of elements strictly less than x
/// find_by_order(x) return x th element of the set (0 based index)
///less dile choto theke boro sajano
///less equal dile multiset er moto kaj kore
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
#define int long long
long long t = 1;
constexpr bool multiple_test_cases = 1;
long long gcd(long long x, long long y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
long long lcm(long long x, long long y)
{
    return ((x * y) / gcd(x, y));
}
long long fact(long long n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
long long findXor(long long n){//reming: function calling findXor(sending value - 1);
    long long rest = n % 4;
    if(rest == 0) return n;
    if(rest == 1) return 1;
    if(rest == 2) return n+1;
    if(rest == 3) return 0;
}
// Linear Diophantine Equation ax + by = c;
// if c % gcd( a , b)  == 0 then solution exist otherwise not
//solution by using  Extended Euclidean algorithm one solution
int extgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
// Euler totient function for single call
int phi(int n){
  int ans = n;
  for(int i = 2; i * i <= n ;i++){ 
   if(n % i == 0){
       ans /= i;
       ans *= (i-1);
       while(n % i== 0) n/= i;
   }
  }
  if(n > 1) ans /= n , ans *= (n - 1);
  return ans;
}
//Euler totient preprocessing(from 1 to n ) in O(nloglog(n))
vector<int>phai(1e7+10);
void init(){
// here check the problem requirement
     int maxn = 1e7+10;
     for(int i = 1; i <= maxn; i++){
       phai[i] = i;
     }
     for(int i = 2; i<= maxn; i++){
       if(phai[i] == i){
         for(int j = i; j <= maxn; j+=i){
           phai[j]/=i; phai[j] *= (i-1);
         }
       }
     }
     // here is the prefix sum of phai function
     // for(int i = 1; i <= maxn; i++){
     //     phai[i] += phai[i-1];
     // }
}
string preprocess(const string &s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }
    return t;
}

string longestPalindromicSubstring(const string &s) {
    if (s.empty()) return "";

    string t = preprocess(s);
    int n = t.size();
    vector<int> P(n, 0);
    int center = 0, right = 0;

    int maxLen = 0, centerIndex = 0;

    for (int i = 0; i < n; ++i) {
        int mirror = 2 * center - i;

        if (i < right)
            P[i] = min(right - i, P[mirror]);

        // Try to expand around i
        while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 &&
               t[i + P[i] + 1] == t[i - P[i] - 1]) {
            ++P[i];
        }

        // Update center and right boundary
        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }

        // Track the max
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    // Extract the longest palindrome from the original string
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}
// for odd length palindrome, p[i] = length of longest palindromic substring centered at i
// for even length palindrome, p[i] = length of longest palindromic substring centered between i and i+1
// the length of the longest palindromic substring is p[i] + 1 or p[i] + 2 depending on whether i is odd or even
// the number of palindromic substrings is (p[i] + 1) / 2 for odd length and (p[i] + 2) / 2 for even length
// total number of palidromic substr. count formula
  //1.total += (p[i] + 1) / 2for odd length and 
  //2.total += (p[i] + 2) / 2 for even length
void solve(){
    string s;
    cin >> s;
    
    string r = longestPalindromicSubstring(s);
    cout << r << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}