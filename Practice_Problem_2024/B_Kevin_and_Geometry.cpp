 
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
bool comp(pair<int , int>&a , pair<int , int>&b){
    return a.first < b.first or a.first == b.first and a.second < b.second;
}
void solve(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    int ans = 0 ;
    map<int , int>mp;
    int cnt = 0 , ft= 0;
    for(auto &x:v) mp[x]++;
    for(auto &x:mp){
        if(x.second >= 4){
            cout << x.first << " "<< x.first << " "<< x.first << " "<< x.first << sad;
            return;
        }
        if(x.second >= 2){
            cnt++;
            if(cnt == 2){
                cout << ft << " "<< ft << " ";
                cout << x.first << " "<< x.first << sad;
                return;
            }
            ft = x.first;
        }
    }
    if(cnt == 0){
        cout << -1 << sad;
        return;
    }
    sort(all(v));
    for(int i = 0 ;i < n-1 ;i++){
        if(v[i] == v[i+1]){
            int ind = -1;
            for(int j = 0 ; j < n ; j++){
                if(j == i ){
                    if(i-1 >= 0) ind = i-1;
                    j+=2;
                    
                }
                
                if(ind != -1){
                    
                    if(v[j] - v[ind] < 2 * v[i]){
                        cout << v[i] << " "<< v[i] << " "<< v[j] << " "<< v[ind] << sad;
                        return;
                    }
                    ind = -1;
                }
                else if(j + 1 < n and j + 1 != i and v[j+1] - v[j] < 2 * v[i]){
                    cout << v[i] << " "<< v[i] << " "<< v[j] << " "<< v[j+1] << sad;
                    return;
                }
            }
            
        }
    }
    cout << -1 << sad;
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