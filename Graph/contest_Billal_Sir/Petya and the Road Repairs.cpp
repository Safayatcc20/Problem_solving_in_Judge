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
const long long N = 1e6+10;
map<long long , long long>mp;
int parent[N], sz[N];
multiset<long long>szl;
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
        if(mp[u] == 1){
            parent[v] = u;
            sz[u] += sz[v];
        }
        else if(mp[v] == 1){
            parent[u] = v;
            sz[v] += sz[u];
        }
        else{
            parent[v] = u;
            sz[u] += sz[v];
        }
    }
}
void solve(){
    long long n , m;
    cin >> n >> m;
    vector<long long>v(n);
    for(long long i = 1; i <= n; i++){
        long long x ;
        cin >> x;
        if(x == 1 ){
            mp[i] = 1;
        }
    }
    vector<pair<long long , pair<long long  , long long>>>edges;
    vector<pair<long long , pair<long long  , long long>>>edge;
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
        if(mp[u] and mp[v]) continue;
        ans += w;
    }
    long long con = 0;
    for(long long i = 1 ; i <= n; i++){
        if(!mp[find(i)]){
            cout << "impossible" << sad;
            return;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
}