 
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

void dfs(int p, int koitaconnected,vector<vector<int>>&v, vector<int>&vis, vector<int>&color, map<pair<int , int>, int>&mp){
    color[p] = koitaconnected;
    //cout << koitaconnected << sad;
    vis[p] = 1;
    for(auto &x:v[p]){
        if(vis[x] == 0 and mp[{p , x}] == 0){
            dfs(x , koitaconnected , v , vis , color, mp);
        }
    }
}
void solve(){
    int n, m1 ,m2;
    cin >> n>>m1 >> m2;
    vector<vector<int>>v(n);
    for(int i = 0 ; i< m1; i++){
        int x ,y;
        cin >> x >>y;
        x--,y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<vector<int>>vv(n);
    for(int i = 0 ; i< m2; i++){
        int x ,y;
        cin >> x >>y;
        x--,y--;
        vv[x].push_back(y);
        vv[y].push_back(x);
    }
    map<pair<int , int>, int>mp;
    vector<int>vis(n,0);
    vector<int>color(n , 0);
    int koitaconnectedache = 0 ;
    for(int i = 0 ; i< n;i++){
        if(vis[i] == 0){
            koitaconnectedache++;
            //cout << koitaconnectedache << sad;
            dfs(i, koitaconnectedache, vv , vis, color,mp);
        }
    }
    int koitaarmvkorbho = 0;
    for(int i = 0 ; i< n;i++){
        for(auto &x:v[i]){
            if(color[i] != color[x]){
                //cout << i << " "<< x << sad;
                koitaarmvkorbho++;
                mp[{i , x}] = 1;
            }
        }
    }
    for(int i = 0 ; i < n;i++){
        vis[i] = 0;
    }
    for(int i = 0 ;i < n; i++){
        if(vis[i] == 0){
            koitaconnectedache--;
            //cout << i << " ";
            dfs(i, koitaconnectedache, v, vis, color, mp);

        }
    }
    
    //cout << koitaarmvkorbho << " " << koitaconnectedache << " "<< koitaaddkorbo << sad;
    cout << koitaarmvkorbho/2 - koitaconnectedache << sad;
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