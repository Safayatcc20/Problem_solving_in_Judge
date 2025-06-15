 
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
 int dp[61][61][61] ;
 int bit = 61;
 const int inf = 1e18;
 void solve(){
    int x , y ;
    cin >> x >> y;
    int ans = inf;
    vector<pair<int  ,int>>v;
    for(int i = 0 ; i < bit ;i++){
        for (int j = 0 ;j < bit; j++){
            if((x >> i) == (y >> j)){
                //cout << dp[bit-1][i][j] << " ";
                ans = min(ans , dp[bit-1][i][j]);
                // v.push_back({i , j});
            }
        }
        //cout << sad;
    }
    cout << ans << sad;
 }
 int32_t main()
 {
     ios_base::sync_with_stdio(0);
     cin.tie(nullptr)->sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     // long long t;
     cin >> t;
     for(int i = 0 ; i<bit;i++){
         for(int j = 0 ; j < bit; j++){
             for(int k = 0 ; k < bit ; k++){
                 dp[i][j][k] = inf;
             }
         }
     }
     dp[0][0][0] = 0;
     for(int k = 0; k < bit-1; k++){
         for(int i = bit -1 ; i >= 0 ; i--){
             for(int j = bit-1; j>= 0; j--){
                dp[k+1][i][j] = dp[k ][i][j];
                if(dp[k][i][j] == inf) continue;
                if(i + k < bit){
                    dp[k+1][i+k][j] = min(dp[k][i+k][j], dp[k][i][j] + (1LL<<k));
                    dp[k+1][i][j] = min(dp[k][i][j], dp[k][i][j] );
                    
                }
                if(j + k < bit){
                    dp[k+1][i][j+k] = min(dp[k][i][j+k], dp[k][i][j] + (1LL<<k));
                    dp[k+1][i][j] = min(dp[k][i][j], dp[k][i][j] );
                }
                //cout << i+k << " "<< j + k<< " "<< k+1 << " "<< dp[k+1][i+k][j]<<" hello "<< dp[k+1][i][j+k]<< sad;
            
                    
             }
         }
     }
     while (t--)
     {
         solve();
     }
 }