#include <bits/stdc++.h>
using namespace std;

void add(vector<int> &p){
    int a,b;
    char c,d;
    cin>>a>>c>>b>>d;
    int ma=max(a,b);
    int mn=min(a,b);
    p[find(ma, p)]=find(mn, p);
}

int find(int i,vector<int> &p){
    if(p[i]!=i){
        p[i]=find(p[i],p);
    }
    return p[i];
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) p[i]=i;

    for(int i=0;i<m;i++){
        add(p);
    }

    for(int i=1;i<=n;i++) {
        find(i,p);
    }

    map<int,int> mp;
    for(int i=1;i<=n;i++){
        mp[find(i, p)]++;
    }

    int a1=0,a2=0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it->second == 1) {
        a2++;
    } else {
        a1++;
    }


    cout<<a1<<' '<<a2;
    return 0;
}
