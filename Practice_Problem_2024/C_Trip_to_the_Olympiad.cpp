 
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
    int l , r;
    cin >> l >> r;
    if(r- l == 2){
        cout << l << " "<< l + 1 << " "<< r << sad;
        return;
    }
    bitset<32>a(r);
    bitset<32>b(l);
    bitset<32>c(l);
    bitset<32>chk(l);
    // cout << (l^r) << sad;
    int msb = -1, smsb = -1;
    for(int i =31 ;i >= 0; i--){
        if(a[i] == 1 and msb ==-1) {
            msb = i;
        }
        if(a[i] == 1 and msb != i) {
            smsb = i;
            break;
        }
    }
    //cout << msb << sad;
    if(smsb == -1) smsb = msb;
    for(int i = 0; i <= msb; i++){
        if(a[i] == 0) b[i] = 1;
        if(a[i] == 1) b[i] = 0;
    }
    for(int i  = msb ; i>=0; i--){
        int bval = b.to_ulong();
        //cout << b[i] << sad;
        if(bval <= r and bval >= l){
            break;
        }
        else{
            if(bval > r) b[i] = 0;
            if(bval < l) b[i] = 1;
        }
        //cout<< b.to_ulong() <<  " ";
    }
    // if(b.to_ulong() < l){
    //     for(int i = smsb; i >= 0 ; i--){
    //         int bval = b.to_ulong();
    //        // cout << b[i] << sad;
    //         if(bval <= r and bval >= l){
    //             break;
    //         }
    //         else{
    //             b[i] = 1;
    //         }
    //         //cout<< b.to_ulong() <<  " ";
    //     }
    // }
    // if(b.to_ulong() >r){
    //     for(int i = smsb; i >= 0 ; i--){
    //         int bval = b.to_ulong();
    //        // cout << b[i] << sad;
    //         if(bval <= r and bval >= l){
    //             break;
    //         }
    //         else{
    //             b[i] = 0;
    //         }
    //         //cout<< b.to_ulong() <<  " ";
    //     }
    // }
    
    for(int i = 0; i <= msb; i++){
        if(b[i] == 0) c[i] = 1;
        if(b[i] == 1) c[i] = 0;
    }
    for(int i  = msb ; i>=0; i--){
        int bval = c.to_ulong();
        //cout << b[i] << sad;
        if(bval <= r and bval >= l){
            break;
        }
        else{
            if(bval > r) c[i] = 0;
            if(bval < l) c[i] = 1;
        }
    }
    // if(c.to_ulong() < l){
    //     for(int i = smsb; i >= 0 ; i--){
    //         int cval = c.to_ulong();
    //         //cout << c[i] << sad;
    //         if(cval <= r and cval >= l){
    //             break;
    //         }
    //         else{
    //             c[i] = 1;
    //         }
    //        // cout<< c.to_ulong() <<  " ";
    //     }
    // }
    // if(c.to_ulong() >r){
    //     for(int i = smsb; i >= 0 ; i--){
    //         int bval = c.to_ulong();
    //        // cout << b[i] << sad;
    //         if(bval <= r and bval >= l){
    //             break;
    //         }
    //         else{
    //             c[i] = 0;
    //         }
    //         //cout<< b.to_ulong() <<  " ";
    //     }
    // }
    //c = b.to_ulong() + 1;
    //cout << c.to_ulong()<< " ";
    if(b!= r and c != r) {
        //cout << r << sad;
        int bb = b.to_ulong() , cc = c.to_ulong();
        cout << bb << " " << cc << " "<< r << " ";
        // cout << ((bb^cc) + (cc ^ r) + (r ^ bb) )<< sad;
    }
    else if(b!= l and c != l) {
        //cout << l << sad;
        int bb = b.to_ulong() , cc = c.to_ulong();
        cout << bb << " " << cc << " "<< l << " ";
        // cout << ((bb^cc) + (cc ^ l) + (l ^ bb)) << sad;
    }
    else{
        int bb = b.to_ulong() , cc = c.to_ulong();
        int x=(cc^bb);
        if(x < l ) x = l+ 1;
        else if(x==l and (bb==l or cc == l)) x = l+1;
        else if(x > r) x = r-1;
        else if(x==r and (bb==r or cc == r)) x = r-1;
        cout << bb << " " << cc << " "<< x << " ";
        // cout << ((bb^cc) + (cc ^ x) + (x ^ bb)) << sad;
    }
    cout << sad;
    // int x = 7, y = 16, z = 11;
    // cout << (x ^ y) + ( y ^ z) + ( z^ x) << sad;
/* 
 
void solve(){
    int l , r;
    cin >> l >> r;
    if(r- l == 2){
        cout << l << " "<< l + 1 << " "<< r << sad;
        return;
    }
    bitset<32>a(r);
    bitset<32>b(l);
    bitset<32>c(l);
    bitset<32>chk(l);
    // cout << (l^r) << sad;
    int msb = -1, smsb = -1;
    for(int i =31 ;i >= 0; i--){
        if(a[i] == 1 and msb ==-1) {
            msb = i;
        }
        if(a[i] == 1 and msb != i) {
            smsb = i;
            break;
        }
    }
    //cout << msb << sad;
    if(smsb == -1) smsb = msb;
    for(int i = 0; i < smsb; i++){
        if(a[i] == 0) b[i] = 1;
        if(a[i] == 1) b[i] = 0;
    }
    //cout<< b.to_ulong() <<  " ";
    for(int i  = smsb ; i<=msb; i++){
        int bval = b.to_ulong();
        if(bval <= r and bval >= l){
            break;
        }
        else{
            b[i] = 1;
        }
    }
    
    for(int i = 0; i <= smsb-1; i++){
        if(b[i] == 0) c[i] = 1;
        if(b[i] == 1) c[i] = 0;
    }
    for(int i  = smsb ; i<=msb; i++){
        int bval = c.to_ulong();
        if(bval <= r and bval >= l){
            break;
        }
        else{
            c[i] = 1;
        }
    }
    //c = b.to_ulong() + 1;
    //cout << c.to_ulong()<< " ";
    if(b!= r and c != r) {
        //cout << r << sad;
        int bb = b.to_ulong() , cc = c.to_ulong();
        cout << bb << " " << cc << " "<< r << " ";
        cout << ((bb^cc) + (cc ^ r) + (r ^ bb) )<< sad;
    }
    else if(b!= l and c != l) {
        //cout << l << sad;
        int bb = b.to_ulong() , cc = c.to_ulong();
        cout << bb << " " << cc << " "<< l << " ";
        cout << ((bb^cc) + (cc ^ l) + (l ^ bb)) << sad;
    }
    int x = 134, y = 132, z = 137;
    cout << (x ^ y) + ( y ^ z) + ( z^ x) << sad;
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
*/
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