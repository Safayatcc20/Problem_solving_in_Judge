// image_cc_full_dsu.cpp
#include <bits/stdc++.h>
using namespace std;
struct DSU {
    int n;
    vector<int> p, sz;
    DSU(int n=0){ init(n); }
    void init(int n_){
        n = n_;
        p.resize(n);
        sz.assign(n,1);
        for(int i=0;i<n;i++) p[i]=i;
    }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b];
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; // n rows, m cols
    if(!(cin>>n>>m)) return 0;
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin >> grid[i]; // assume '.' white, '#' black (or use '0'/'1')
    auto idx = [&](int r,int c){ return r*m + c; };
    DSU dsu(n*m);
    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            if(grid[r][c]=='#') continue;
            if(c+1<m && grid[r][c+1]=='.') dsu.unite(idx(r,c), idx(r,c+1));
            if(r+1<n && grid[r+1][c]=='.') dsu.unite(idx(r,c), idx(r+1,c));
        }
    }
    unordered_map<int,int> compSize;
    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            if(grid[r][c]=='.'){
                compSize[ dsu.find(idx(r,c)) ]++;
            }
        }
    }
    // print sizes (representative -> size)
    cout << "Number of components: " << compSize.size() << "\n";
    for(auto &kv : compSize){
        cout << "root="<<kv.first<<" size="<<kv.second<<"\n";
    }
    return 0;
}
