 
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
    int n;
    cin>>n;
    vector<int>v(n+1);
    int two = 1,cnt = 1;
    while(two * 2 < n){
        two *=2;
        cnt++;
    }
    if(n &1){
        cout << n << sad;
        int p = two-1;
        v[n-4+1] = 1;
        v[n-4+2] = 3;
        v[n-4+3] = n-1;
        v[n-4] = n;
        map<int , int>mp;
        mp[1] = 1;
        mp[3] = 1;
        mp[n-1] = 1;
        mp[n] = 1;
        for(int i = 1; i<= n;i++){
            if(mp[i]) continue;
            cout << i << " ";
        }
        cout << 1 << " "<< 3 <<  " "<< n-1 << " "<< n << sad;
    }
    else{
        if(two * 2 == n){
            cout << n*2-1 << sad;
            v[n-5+1] = 1;
            v[n-5+2] = 3;
            v[n-5+3] = n-2;
            v[n-5+4] = n-1;
            v[n] = n;
            map<int , int>mp;
            mp[1] = 1;
            mp[3] = 1;
            mp[n-2] = 1;
            mp[n-1] = 1;
            mp[n] = 1;
            for(int i = 1; i<= n;i++){
                if(mp[i]) continue;
                cout << i << " ";
            }
            cout << 1 << " "<< 3 <<  " "<<n-2 << " "<< n-1 << " "<< n << sad;
        }
        else
        {   
            cout << two*2-1 << sad;
            int p = two-1;
            v[n-4+1] = two;
            v[n-4+2] = n;
            v[n-4+3] = n-1;
            v[n] = two-1;
            map<int , int>mp;
            mp[two-1] = 1;
            mp[two] = 1;
            mp[n-1] = 1;
            mp[n] = 1;
            for(int i = 1; i<= n;i++){
                if(mp[i]) continue;
                cout << i << " ";
            }
            cout << two << " "<< n <<  " "<< n-1 << " "<< two-1 << sad;
        }

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