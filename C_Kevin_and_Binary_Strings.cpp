 
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
void solve(){
    string s;
    cin >> s;
    int n  = s.size(), ind = -1;
    for(int i = 0 ; i < n; i++){
        if(s[i] == '0'){
            ind = i+1;
            break;
        }
    }
    if(ind == -1){
        cout << 1 << " "<< n << " ";
        cout << n << " "<< n << sad;
        return;
    }
    else{
        //cout << ind << sad;
        vector<vector<char>>v(n , vector<char>(n));
        vector<vector<char>>chk(n , vector<char>(n));
        for(int j = 0 ; j < n ;j++){
            for(int i = 0 ;i < n ; i++){
                chk[j][i] = '.';
            }
        }
        for(int i = 0 ; i < n ;i++){
            for(int j = ind-1; j< n;j++){
                if(s[i] != s[j]) v[j][i] = '1';
                else v[j][i] = '0';
            }
        }
        int c = 0;
        for(int i = ind-1; i<n; i++){
            for(int j = 0;j < n;j++){
                if(i-c >= 0 and j + c < n) 
                {
                    // cout << j << " "<< i - c << " ";
                    // cout << i << " "<< j + c << " "<< v[i][j+c] << sad;
                    chk[j][i] = v[i][j+c];
                }
            }
            c++;
        }
        // for(int j = 0 ; j < n ;j++){
        //     for(int i = 0 ;i < n ; i++){
        //         cout << v[j][i] << " ";
        //     }
        //     cout <<"he"<<sad;
        // }
        // for(int j = 0 ; j < n ;j++){
        //     for(int i = 0 ;i < n ; i++){
        //         //cout << j << " "<< i << " ";
        //         cout << chk[j][i] <<" ";
        //     }
        //     cout <<"hde"<<sad;
        // }
        
        vector<pair<string , pair<int , int>>>ans;
        for(int i = 0 ; i < n ;i++){
            string cr="";
            int nj = n-ind+1;
            bool f = false,nibo = false;
            for(int j = 0 ; j < n ;j++){
                
                if(f and chk[i][j] == '.') {
                    nibo = true;
                    break;
                }
                else{
                    if(!f and chk[i][j] =='.') {
                        continue;
                    }
                    else f = true;
                    cr+= chk[i][j];
                }
            }
            if(nibo) continue;
            //cout << cr << sad;
            ans.push_back({cr , {i+1 , nj+i}});
        }
        sort(all(ans));
        // for(auto &x:ans){
        //     cout << x.first << " "<< x.second.first << " "<< x.second.second << sad;
        // }
        int val =ans.size()-1;
        cout << 1 << " " << n << " ";
        cout << ans[val].second.first << " " << ans[val].second.second << sad;
    }
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