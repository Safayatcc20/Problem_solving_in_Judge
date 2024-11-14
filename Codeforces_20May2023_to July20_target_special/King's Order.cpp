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
int parent[N], sz[N] ;
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
vector<pair<long long , pair<long long  , long long>>> work(vector<pair<long long , pair<long long  , long long>>>&edges, long long n){
    sort(all(edges));
    int ans = 0, cnt = 0;
    vector<pair<long long , pair<long long  , long long>>>mst;
    map<long long , long long>city;
    for(long long i = 1 ; i <= n; i++) make(i);
    for(auto &x:edges){
        long long w = x.first;
        long long u = x.second.first;
        long long v = x.second.second;
        if(find(u) == find(v)) continue;
        Union(u , v);
        city[u] = 1;
        city[v] = 1;
        mst.push_back({u , {v , w}});
        //cout << u << " " << v << sad;
    }
    return mst;
}
void solve(){
    long long n , m;
    cin >> n >> m;
    bool f = false;
    vector<pair<long long , pair<long long  , long long>>>edges;
    for(long long i = 0 ; i < m; i++){
        long long u , v , w;
        cin >> u >> v >> w;
        if(u == n || v== n) f = true;
        edges.push_back({w , {u , v}});
    }
    int cnt = 0;
    vector<pair<long long , pair<long long  , long long>>>mst = work(edges , m);
    if(mst.size() < n-1){
        cout << "Not Possible" << sad;
    }
    else{
        long long ans = 0;
        for (auto &edge : mst) {
            ans += edge.second.second;
        }
        cout << m - mst.size() << " " << ans << sad;
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