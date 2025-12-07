// graph_cc.cpp
#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> p, sz;
    DSU(int n=0){ init(n); }
    void init(int n){
        p.resize(n); sz.assign(n,1);
        for(int i=0;i<n;i++) p[i]=i;
    }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b];
        return true;
    }
    bool same(int a,int b){ return find(a)==find(b); }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; 
    if(!(cin>>n>>m)) return 0;
    DSU dsu(n);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v; // assume 0-based
        dsu.unite(u,v);
    }
    int q; cin>>q;
    while(q--){
        int a,b; cin>>a>>b;
        cout << (dsu.same(a,b) ? "YES" : "NO") << '\n';
    }
    return 0;
}
