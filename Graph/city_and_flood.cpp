/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
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
const long long N = 1e6+ 5;
long long parent[N] , sz[N];
long long prime[N];
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
void make(long long v){
    parent[v] = v;
    sz[v] = 1;
}
long long find(long long v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}
void Union(long long u , long long v){
    u = find(u);
    v = find(v);
    if(u != v){
        if(u < v){
            swap(u , v);
        }
        parent[v] = u;
        sz[u] += sz[v];
    }
}
void solve(){
    long long n , k;
    cin >> n >> k;
    for(long long i = 1; i <= n; i++){
        make(i);
    }
    for(long long i = 0 ; i < k ; i++){
        long long u , v;
        cin >> u >> v;
        Union(u , v);
    }
    long long ans = 0;
    for(long long i = 1 ; i <= n; i++){
        if(i == find(i)){
            ans++;
        }
    }
    cout << ans << sad;
}
int main()
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