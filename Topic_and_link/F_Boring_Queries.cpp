// #include<bits/stdc++.h>
// using namespace std;
// #define mx 200050 * 1LL
// const int inf = 2000000000;
// const int mod = 1e9+7;
// int bin_power(int a, int n ,int mod) {
//   int ans = 1% mod;
//   while(n){
//     if(n & 1) ans = 1LL * ans * a % mod;
//     a = 1LL * a * a % mod;
//     n >>= 1;
//   }
//   return ans;
// }

// // 1 / a % p
// int inverse(int a, int p) {
//   return bin_power(a, p - 2, p);
// }
// long long gcd(long long x, long long y)
// {
//     if (y == 0)
//         return x;
//     return gcd(y, x % y);
// }
// long long lcm(long long x, long long y)
// {
//     return (((x * y)%mod) * inverse(gcd(x, y), mod) % mod);
// }
// int arr[mx];
// int tree[mx * 4 ];// space 4 * N neya hoi contest er somoy but 3 * N neya better 
// void build(int node, int begin, int end) {
//     if (begin == end) {
//         tree[node] = arr[begin];
//         return;
//     }
//     int left =  2 * node;
//     int right =  2 * node + 1;
//     int mid = (begin + end) / 2;
//     build(left, begin, mid);
//     build(right, mid + 1, end);
//     tree[node] = lcm(tree[left], tree[right])%mod; // Update tree[node] with the min of left and right children
// }

// // segment tree query
// // here i  and j is the starting and ending possition of given array or tree
// // begin and end is the of range query
// //  
// // query and update O(log(n))
// int query(int node , int begin , int end , int i , int j){
//     if( i > end or j < begin){
//         return 1;//No overlap 
//     }
//     if(begin >= i and end <= j){
//         return tree[node] ; // Total overlap;
//     }
//     // Partial overlap
//     // jodi 0 index e hoi left = node * 2 + 1 , right = node * 2 + 2 hobe;
//     int left = node * 2;// 1 base indexing
//     int right = node * 2 + 1;
//     int mid = ( begin  + end) / 2;
//     int x = query(left , begin, mid , i , j);
//     int y = query(right ,  mid + 1,end , i , j);
//     return lcm( x  , y)%mod; // finding minimum range query
// }
// void update(int node , int begin , int end , int i , int newvalue){
//     if( i > end or i < begin){
//         return ;//No overlap 
//     }
//     if(begin >= i and end <= i){
//         arr[i] = node;
//         tree[node]  = newvalue; // update or set value 
//         return ;
//     }
//     // Partial overlap

//     int left = node * 2;// 1 base indexing
//     int right = node * 2 + 1;
//     int mid = ( begin  + end) / 2;
//     update(left , begin, mid , i , newvalue);
//     update(right ,  mid + 1,end , i , newvalue);
//     tree[node] = lcm(tree[left] , tree[right])%mod;
// }
// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(nullptr)->sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int n ; 
//     cin >> n ;
//     for(int i = 1; i <= n ; i++){
//         cin >> arr[i];
//     }
//     for(int i = 1; i <= mx * 4 - 1 ; i++){
//         tree[i] = inf;
//     }
//     int m;
//     cin >> m;
//     build(1, 1 , n);
//     /* cout << query(1 , 1 , n , 1 , 3) << endl;
//     update(1 ,1 , n , 2, 0);
//     cout << query(1 , 1 , n , 1 , 3) << endl;
//     update(1 ,1 , n , 2 , 5);
//     cout << query( 1, 1 , n , 1 , 2 ) << endl; */
//     int ans =  0;
//     while(m--){
//         int t , l , r ;
//         cin >> l >> r;
//         l = (ans + l) % n + 1;
//         r = (ans + r) % n + 1;
//         if(l > r) swap( l , r);
//         ans = query(1 , 1 , n , l , r)%mod;
//         cout << (ans%mod) << endl;
        
//     }
// }
 
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
vector <int> prime;
bool is_composite[1000];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
            cout << i * prime[j] << " ";
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}

}
void solve(){
 
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
   // cin >> t;
   sieve(100);
   cout <<sad;
   for(auto &x:prime){
    cout << x << " ";
   }
    while (t--)
    {
        //solve();
    }
}