
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        vector<int>v(n);
        map<int, int>m;
        for(auto &it:v){
            cin>>it;
        }
        
        for(int i=0; i<k; i++){
            m[v[i]]++;
        }
        
        sort(v.begin(),v.end());
        
        ll ans=0;
        
        for(int i=0; i<k; i++){
            m[v[i]]++;
            if(m[v[i]]==1)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}