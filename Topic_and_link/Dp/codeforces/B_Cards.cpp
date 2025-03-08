 
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
void recdp(int bb , int gg , int rr , vector<vector<vector<int>>>&dp){
    if(bb < 2 or gg > bb or rr > bb - gg) return ;
    if(dp[gg][rr][bb - gg - rr] != 0) return;
    int b = 0 , r = 0 , g =  0;
    int chk = bb - gg - rr ;
    if(gg > 1) {
        dp[gg-1][rr][chk]++;
        recdp(gg-1 ,rr , chk , dp);
    } 
    if(rr > 1) {
        dp[gg][rr-1][chk]++;
        recdp(gg, rr - 1, chk , dp);
    } 
    if(chk > 1) {
        dp[gg][rr][chk-1]++;
        recdp(gg , rr , chk-1 , dp);
    } 
    if(rr and gg) {
        dp[gg-1][rr-1][chk+1]++;
        recdp(gg-1 , rr-1 , chk+1 , dp);
    } 
    if(chk and gg) {
        recdp(gg-1 , rr + 1, chk-1 , dp);
        dp[gg-1][rr+1][chk-1]++;
    } 
    if(rr and chk) {
        dp[gg+1][rr-1][chk-1]++;
        recdp(gg+1 , rr-1 , chk-1 , dp);
    } 
}
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int b = 0 , r = 0 ,g = 0 ;
    vector<vector<vector<int>>>dp(n+5 , vector<vector<int>>(n+5 , vector<int>(n+5 , 0)));
    for(int i = 0 ;i < n ;i++){
        if(s[i] == 'B') b++;
        if(s[i] == 'G') g++;
        if(s[i] == 'R') r++;
    }

    dp[b][g][r] = 1;
    
    //bottom up hobe nah
    for(int i = n; i >=2 ;i--){
        for(int bb = 0 ; bb <= i ; bb++){
            for(int gg = 0; gg <= i - bb; gg++){
                int rr = i - bb - gg;
                if(!dp[bb][gg][rr]) continue;
                if(bb > 1){
                    dp[bb-1][gg][rr]++;
                }
                if(gg > 1){
                    dp[bb][gg-1][rr]++;
                }
                if(rr > 1){
                    dp[bb][gg][rr-1]++;
                }
                if(bb and gg){
                    dp[bb-1][gg-1][rr+1]++;
                }
                if(bb and rr){
                    dp[bb-1][gg+1][rr-1]++;
                }
                if(rr and gg){
                    dp[bb+1][gg-1][rr-1]++;
                }
            }
        }
    }
    string ans;
    if(dp[1][0][0]) ans+= 'B';
    if(dp[0][1][0]) ans+= 'G';
    if(dp[0][0][1]) ans+= 'R';
    cout << ans << sad;
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