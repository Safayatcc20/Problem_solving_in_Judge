 
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
#define all(b) b.rbegin(), b.rend()
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
    int n, m;cin>> n>> m;
    map<int , int>mp;
    vector<vector<int>>v(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
            mp[v[i][j]]++;
        }
    }

    vector<int>bro(n*m+ 1);
    // for(auto &x: mp){
    //     cout << x.first << " " << x.second << sad;
    // }
    for(auto &i: mp){
        int ans = 0 ;
        while(mp[i.first] != 0){
            
            ans++;
            int pos = 0;
            int ind = -1;
            vector<int>vv(m+1);
            vector<int>vvv(m+ 1);
            int x = -1;
            int y = 0;
            for(int j = 0 ; j < n; j++){
                for(int k = 0 ; k <m;k++){
                    if(k + pos < m and v[j][k+pos] == i.first){
                        ind = k;
                        v[j][k+pos] = 0;
                        mp[i.first]--;
                        vv[k+pos]++;
                        pos = 1;
                        x = j;
                    }
                }
                if(x != -1) {
                    break;
                }
            }
            pos =0;
            // cout << x << " " << i.first << sad;
            // for(auto x: vv){
            //     cout << x << " ";
            // }
            // cout << sad;
            for(int j = x+1; j < n; j++){
                int k = 0;
                if(pos == 2) break;
                for(k = 0; k < m; k++){
                    if(k + pos < m and v[j][k + pos] == i.first and vv[k + pos] == 0){
                        vvv[k+pos] = 1;
                        v[j][k+pos] = 0;
                        mp[i.first]--;
                        pos = 1;
                        if(mp[i.first] == 0) {
                            pos = 2;
                            break;
                        }
                    }
                }
                vv.clear();
                vv = vvv;
                vvv.clear();
            }
            if(mp[i.first] == 0)
            bro[i.first] = ans;
        }
    }
    sort(all(bro));
    bool f = false;
    int ans = 0 ;
    for(auto &i: bro){
           
        if(i != 0 and !f) {
            f = true;
        }
        else{
            ans+= i;
        }
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
    while (t--)
    {
        solve();
    }
}