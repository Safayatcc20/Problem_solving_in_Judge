 
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
    int n , d;
    cin >> n >> d;
    vector<int> a;
    vector<int> b;
    for(int i = 0 ; i < n ;i++){
        int x , y;
        cin >> x >> y;
        if(y == 1){
            a.push_back(x);
        }
        else{
            b.push_back(x);
        }
    }
    vector<int> pre(a.size());
    for(int i = 0 ; i < a.size(); i++){
        if(i == 0){
            pre[i] = 0;
        }
        else{
            int ind1 = lower_bound(all(b), max(a[i-1], 0ll)) - b.begin();
            int ind2 = lower_bound(all(b), max(a[i] - 1, 0ll)) - b.begin();
            if(ind1 > b.size()) ind1--;
            if(ind2 > b.size()) ind2--;
            if(b[ind1] > a[i]){
                pre[i] = pre[i-1] ;
            }
            else if(b[ind2] > a[i]){
                ind2 = i-1;
                pre[i] = pre[i-1] + ind2 - ind1 + 1;
            }
            else if(ind1 == ind2){
                pre[i] = pre[i-1] + 1;
            }
            else{
                pre[i] = pre[i-1] + ind2 - ind1 + 1;
            }
        }
    }
    // for(auto &x:pre){
    //     cout << x << " ";
    // }
    // cout << sad;
    // for(auto &x:a){
    //     cout << x << " ";
    // }
    // cout << sad;
    int ans = 0 ;
    for(int i = 1 ; i < a.size(); i++){
        if(i == 1){
            ans += pre[i];
        }
        else{
            int ind1 = lower_bound(all(a), max(a[i] - d+1, 0ll)) - a.begin();
            if(ind1 == i){
                ans += pre[i] - pre[i-1];
            // cout << ind1 << " "<< a[i] << " 1 "<<a[i]-d+1 << " "<< ans<< sad;
            }
            else if(ind1 != i - 1){
                ans += (pre[i] - pre[i-1]) * 2 + pre[i-1] - pre[ind1];
            // cout << ind1 << " "<< a[i] << " 2 "<<a[i]-d+1 << " "<< ans<< sad;
            }
            else{
                ans += pre[i] - pre[i-1];
            // cout << ind1 << " "<< a[i] << " 3  "<<a[i]-d+1 << " "<< ans<< sad;
            }
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
    //cin >> t;
    while (t--)
    {
        solve();
    }
}