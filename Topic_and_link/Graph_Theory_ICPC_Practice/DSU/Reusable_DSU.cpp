// dsu.hpp
#include <vector>
struct DSU {
    int n;
    std::vector<int> parent, sz;
    DSU() : n(0) {}
    DSU(int n_){ init(n_); }
    void init(int n_){
        n = n_;
        parent.resize(n);
        sz.assign(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a,int b){
        a = find(a); b = find(b);
        if(a==b) return false;
        if(sz[a] < sz[b]) std::swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
    int size(int x){ return sz[find(x)]; }
};
