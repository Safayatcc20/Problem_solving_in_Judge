 
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
const long long N = 2e5+10;
long long parent[N] , sz[N] ;//create parent array;
vector<vector<int>>dp(N , vector<int>(11,0));
vector<vector<int>>ind(N , vector<int>(11,0));
vector<vector<int>>st(N , vector<int>(11,0));
vector<vector<int>>lt(N , vector<int>(11,0));
void make(long long v){
    parent[v] = v;// indepent node make
    sz[v] = 1;
}
long long find(long long v){
    if(v == parent[v]){
        return v;//parent or root find  of the group;
    }
    // path compression is here
    return parent[v] = find(parent[v]);//change the parent;
    
}
void Union(long long a , long long b ){//create a set of group 
    a = find(a);//roots of a nodes group; it is left tree(big size tree always);
    b = find(b);// roots of b nodes group; it is right tree(small size tree always);
    if(a != b)//roots are different;
    {
        //union by size
        if(sz[a] < sz[b]){// if a is small size tree then make a is big and b is small;
            swap(a , b);
        }
        parent[b] = a;//parent of b added with parent of a then parent of a , b is parent of a;
        sz[a] += sz[b];//size of a and b are now group;
        //problem solve by size cocept;
    }
}
void solve(){
    // DSU time complexity O(alpha(n));
    // herer alpha(n) is called Reverse ackerman function;it is increase the value so slowly;
    //cp algorithm discuss this code see here link below:
    //https://cp-algorithms.com/data_structures/disjoint_set_union.html#search-for-connected-components-in-an-image'
    long long n , k;
    cin >> n >> k;
    for(int i = 1; i <= n ;i++){
        for(int j= 0 ;j < 11; j++){
            ind[i][j] = i;
            dp[i][j] = 0;
        }
    }
    vector<vector<int>>st(n *2, vector<int>(11));
    vector<vector<int>>lt(n*2 , vector<int>(11));
    for(long long i = 1; i <= n; i++) make(i);
    while(k--){
        int u , v, w;
        cin >> u >> v >> w;
        st[u][v]++;
        lt[u + w * v][v]++;
    }
    for(int i = 1 ; i<= n ;i++){
        for(int j = 1; j <= 10; j++){
            dp[i][j] = st[i][j] - lt[i][j];
            if (i-j > 0 and dp[i-j][j] > 0 ) {
                Union(ind[i - j][j], i);
                ind[i][j] = ind[i - j][j];
                dp[i][j] += dp[i - j][j];
            }
        }
    }
    int connected_component = 0;// how many roots is the connected component;
    for(long long i =  1; i <= n ; i++){
        if(i == find(i)){
            connected_component++;
        }
    }
    cout << connected_component << sad;
    
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