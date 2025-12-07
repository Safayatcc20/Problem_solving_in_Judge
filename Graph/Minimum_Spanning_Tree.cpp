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
const long long N = 1e5+10;
int parent[N], sz[N];
void make(long long v){
    parent[v] = v;
    sz[v] = 1;
}

int find(long long v){
    if(parent[v] == v){
        return parent[v];
    }
    return parent[v] = find(parent[v]);
}
void Union(long long a , long long b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(sz[a] < sz[b]){
            swap(a , b);
        }
        parent[b] = a;
        sz[a] += sz[b]; 
    }
}
void solve(){
    long long n , m;
    cin >> n >> m;
    vector<pair<long long , pair<long long  , long long>>>edges;
    for(long long i = 0 ; i < m; i++){
        long long u , v , w;
        cin >> u >> v >> w;
        edges.push_back({w , {u , v}});
    }
    sort(all(edges));
    int ans = 0 ;
    for(long long i = 1 ; i <= n; i++) make(i);
    for(auto &x:edges){
        long long w = x.first;
        long long u = x.second.first;
        long long v = x.second.second;
        if(find(u) == find(v)) continue;
        Union(u , v);
        ans += w;
        //cout << u << " " << v << sad;
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