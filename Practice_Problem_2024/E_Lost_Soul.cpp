 
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
void solve(){   
    int n ;
    cin >> n ;
    vector<int>v(n) , vv(n);
    for(auto &x: v) cin >> x;
    for(auto &x: vv) cin >> x;
    if(v[n-1] == vv[n-1]){
        cout << n<< sad;
        return;
    }
    map<int, vector<int>>mp, mmp;
    for(int i = 0; i < n ;i++){
        mp[v[i]].emplace_back(i);
        mmp[vv[i]].emplace_back(i);
    }
    
    int ans = -1, lim = -1;
    for(int i = n -1 ;i > lim ; i--){
        int ind = lower_bound(mmp[v[i]].begin() , mmp[v[i]].end(), i-1) - mmp[v[i]].begin();
        // cout << ind << " "<< mmp[v[i]].size() << " "<< v[i]<<" ";
        if(ind == 0){
            if(mmp[v[i]].size() != 0 and mmp[v[i]][ind] < i-1) {
                ans = max(ans , mmp[v[i]][ind]);
                // cout << i <<   " " << ind << " hello "<< mmp[v[i]][ind]<< " "<< ans<< sad;
                // lim = ans;
            }
        }
        else{
            if(mmp[v[i]].size() != 0 and (ind >= mmp[v[i]].size())){
                ind--;
                // cout << " ami "<< " ";
            }
            if(mmp[v[i]].size() != 0 and mmp[v[i]][ind] >= i-1){
                ind--;
                // cout << "amsi2 ";
            }
            if(ind >= 0){
                ans = max(ans , mmp[v[i]][ind]);
                // lim = ans;
                // cout <<  i <<   " " << ind << " hello2 "<< mmp[v[i]][ind]<< " "<< ans<< sad;
            }
        }
        
        // cout << sad;
    }
    for(int i = n -1 ;i > lim ; i--){
        int ind = lower_bound(mp[vv[i]].begin() , mp[vv[i]].end(), i-1) - mp[vv[i]].begin();
        // cout << ind << " "<< mp[vv[i]].size() << " "<< vv[i]<<" ";
        if(ind == 0){
            if(mp[vv[i]].size() != 0 and mp[vv[i]][ind] < i-1) {
                ans = max(ans , mp[vv[i]][ind]);
                // cout << i <<   " " << ind << " hello "<< mp[vv[i]][ind]<< " "<< ans<< sad;
                // lim = ans;
            }
        }
        else{
            if(mp[vv[i]].size() != 0 and (ind >= mp[vv[i]].size())){
                ind--;
                // cout << " ami "<< " ";
            }
            if(mp[vv[i]].size() != 0 and mp[vv[i]][ind] >= i-1){
                ind--;
                // cout << "amsi2 ";
            }
            if(ind >= 0){
                ans = max(ans , mp[vv[i]][ind]);
                // lim = ans;
                // cout <<  i <<   " " << ind << " hello2 "<< mp[vv[i]][ind]<< " "<< ans<< sad;
            }
        }
        
        // cout << sad;
    }
    for(int i = n -1 ;i > lim ; i--){
        int ind = lower_bound(mmp[vv[i]].begin() , mmp[vv[i]].end(), i-1) - mmp[vv[i]].begin();
        // cout << ind << " "<< mmp[vv[i]].size() << " "<< vv[i<<" ";
        if(ind == 0){
            if(mmp[vv[i]].size() != 0 and mmp[vv[i]][ind] < i-1) {
                ans = max(ans , mmp[vv[i]][ind]);
                // cout << i <<   " " << ind << " hello "<< mmp[vv[i]][ind]<< " "<< ans<< sad;
                // lim = ans;
            }
        }
        else{
            if(mmp[vv[i]].size() != 0 and (ind >= mmp[vv[i]].size())){
                ind--;
                // cout << " ami "<< " ";
            }
            if(mmp[vv[i]].size() != 0 and mmp[vv[i]][ind] >= i-1){
                ind--;
                // cout << "amsi2 ";
            }
            if(ind >= 0){
                ans = max(ans , mmp[vv[i]][ind]);
                // lim = ans;
                // cout <<  i <<   " " << ind << " hello2 "<< mmp[vv[i]][ind]<< " "<< ans<< sad;
            }
        }
        
        // cout << sad;
    }
    for(int i = n -1 ;i > lim ; i--){
        int ind = lower_bound(mp[v[i]].begin() , mp[v[i]].end(), i-1) - mp[v[i]].begin();
        // cout << ind << " "<< mp[v[i]].size() << " "<< v[i]<<" ";
        if(ind == 0){
            if(mp[v[i]].size() != 0 and mp[v[i]][ind] < i-1) {
                ans = max(ans , mp[v[i]][ind]);
                // cout << i <<   " " << ind << " hello "<< mp[v[i]][ind]<< " "<< ans<< sad;
                // lim = ans;
            }
        }
        else{
            if(mp[v[i]].size() != 0 and (ind >= mp[v[i]].size())){
                ind--;
                // cout << " ami "<< " ";
            }
            if(mp[v[i]].size() != 0 and mp[v[i]][ind] >= i-1){
                ind--;
                // cout << "amsi2 ";
            }
            if(ind >= 0){
                ans = max(ans , mp[v[i]][ind]);
                // lim = ans;
                // cout <<  i <<   " " << ind << " hello2 "<< mp[v[i]][ind]<< " "<< ans<< sad;
            }
        }
        
        // cout << sad;
    }

    for(int i = 0 ; i < n-1; i++){
        if(v[i] == v[i+1]){
            ans = max(ans , i);
        }
        if(vv[i] == vv[i+1]){
            ans = max(ans , i);
        }
        if(v[i] == vv[i]) {
            ans = max(ans , i);
        }
    }
    for(int i = 0 ; i < n-2; i++){
        if(v[i] == v[i+2]){
            ans = max(ans , i);
        }
        if(vv[i] == vv[i+2]){
            ans = max(ans , i);
        }
    }
    cout << ans+1 << sad; 
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