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
const long long N = 1e5 + 5;
long long parent[N] , sz[N];
multiset<long long>szl;
void make(long long v){
    parent[v] = v;
    sz[v] = 1;
    szl.insert(1);
}
long long find(long long v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}
void merge(long long a , long long b){//tree merge
    szl.erase(szl.find(sz[a]));
    szl.erase(szl.find(sz[b]));
    szl.insert(sz[a] + sz[b]);
}
void Union(long long u , long long v){
    u = find(u);
    v = find(v);
    if(u != v){
        if(u < v){
            swap(u , v);
        }
        parent[v] = u;
        merge(u , v);
        sz[u] += sz[v];
    }
}
void solve(){
    long long n , q;
    cin >> n >> q;
    for(long long i = 1; i <= n; i++) make(i);
    for(long long i = 0 ; i < q ; i++){
        long long u , v;
        cin >> u >> v;
        Union(u , v);
        if(szl.size() == 1){
            cout << 0 << sad;
        }
        else{
            int mn = *(szl.begin());
            int mx = *(--szl.end());
            cout << mx - mn << sad;
        }
    }
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