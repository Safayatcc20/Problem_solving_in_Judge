 
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
 //key shortcut ctrl + d u can select same name for this 
// remember mod depends on statement;
const long long mod = 1e9+7;
int bin_power(int a, int n ,int mod) {
  int ans = 1% mod;
  while(n){
    if(n & 1) ans = 1LL * ans * a % mod;
    a = 1LL * a * a % mod;
    n >>= 1;
  }
  return ans;
}
bool isSetBit(int val, int pos) {
   return (val & (1LL << pos)) != 0;
}

void setBit(int &val, int pos) { 
    val = (val | (1LL << pos)); 
} 

void clearBit(int &val, int pos) { 
    val = (val & (~(1LL << pos))); 
} 

void printbin(int a) {
    bitset<32> decimal(a);
    cout << decimal << '\n';
}

void printdeci(string a) {
    bitset<32> deci(a);
    int x = deci.to_ulong();
    cout << x << '\n';
}
int findMSB(int num) {
    if (num == 0) return -1;  // No MSB if the number is zero
    int msbPos = 0;
    while (num > 1) {
        num >>= 1;
        msbPos++;
    }
    return msbPos;
}
//Count the number of trailing zeros in a binary number
int countTrailingZeros(int num) {
    if (num == 0) return 32; // If num is zero, all bits are zero
    int count = 0;
    while ((num & 1) == 0) {
        num >>= 1;
        count++;
    }
    return count;
}
// Count the number of leading zeros in a binary number
int countLeadingZeros(int num) {
    if (num == 0) return 32; // If num is zero, all bits are zero
    int count = 0;
    int bitLength = 31; // For a 32-bit integer
    while ((num & (1 << bitLength)) == 0) {
        count++;
        bitLength--;
    }
    return count;
}
void solve(){
    int n;
    cin >> n;
    vector<int>v(n);
    int ans = 0 ;
    vector<pair<int, int>>chk;
    for(int i = 0 ;  i< n; i++){
        cin >>v[i];
        int x = countTrailingZeros(v[i]);
        cout << x << " "<< v[i] << " after ";
        int nv = v[i] >> x;
        cout << x << " "<< (nv<<x) << sad;
        while(!chk.empty()){
            cout << chk.back().first <<  " ";
            if(x >= 30 or chk.back().first <= (nv<<x)){
                x += chk.back().second;
                ans += chk.back().first;
                chk.pop_back();
            }
            else break;
        }
        if(x== 0) ans += nv;
        else chk.emplace_back(nv , x);
        int aans = ans;
        cout << ans << " " << chk.size() << sad;
        for(auto &y:chk){
            aans+= bin_power(2 , y.first , mod) * y.second % mod;
        }
        cout << aans % mod << sad;
        //cout << aans % mod << " ";
    }
    cout << sad;
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