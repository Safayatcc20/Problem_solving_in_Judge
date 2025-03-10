 
 /***** Bismillahir Rahmanir Rahim *****/
 
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using oset = tree<T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

bool func(string s, string t) {
    int n = s.size();
    int f = -1, e = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] != t[i] and f == -1) {
            f = i;
        } 
        if(s[i] != t[i]) {
            e = i;
        }
    }
    if(f == -1) return true;
    reverse(s.begin()+f,s.begin()+e + 1);
    return s == t;
}

void solve(){
    int x1, y1, z1;
    cin >> x1 >> y1 >> z1;
    int x2, y2, z2;
    cin >> x2 >> y2 >> z2;
    int k; cin >> k;
    int a = abs(x1 - x2);
    int b = abs(y1 - y2);
    int c = abs(z1 - z2);
    vector<int> v;
    v.push_back(a);
    v.push_back(c);
    v.push_back(b);
    sort(all(v));
    // int ans = v[0] + min(v[0] * k, v[2]);
    // v[2] -= min(v[0] * k, v[2]);
    // v[0] = 0;
    // sort(all(v));
    // ans += v[1] + min(v[1] * k, v[2]);
    // v[2] -= min(v[1] * k, v[2]);
    // ans += min(k, v[2]);
    // v[2] -= k;
    // ans += v[2] + v[2] / k;
    int ans = 0;
    int kotolagbe = (v[1] + k -1)  / k;
    ans += min(v[0] , kotolagbe) + min(kotolagbe * k,v[1]);
    v[1] -=min(kotolagbe * k,v[1]);
    v[0] = v[0] - min(v[0] , kotolagbe);
    int secondcontribution =  min(kotolagbe * k * k , v[2]);
    cout << secondcontribution<< " ";
    ans += secondcontribution;
    v[2] = v[2] - secondcontribution;
    sort(all(v));
    cout << v[0] << " ";
    cout << v[1] << " ";
    cout << v[2] << " ";
    kotolagbe = (v[2] + k -1)  / k;
    ans += min(v[1] , kotolagbe) + min(kotolagbe * k,v[2]);
    v[2] -=min(kotolagbe * k,v[2]);
    v[1] = v[1] - min(v[1] , kotolagbe);
    if(v[1]) ans += v[1] + v[1]/k;
    if(v[2]) ans += v[2] + v[2]/k;
    cout << ans << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}