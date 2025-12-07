#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        for(int i=0; i<n; i++)cin>>a[i];
        for(int i=0; i<n; i++)cin>>b[i];
        
     
        map<int,int>mpa,mpb;
        int ans=0;
        for(int i=0;i<n; i++){
            if(i%2==0){
                mpa[a[i]]=i+1;
                mpb[b[i]]=i+1;
            }
            else{
                mpa[b[i]]=i+1;
                mpb[a[i]]=i+1;
            }
            ans=max(ans,min(mpa[a[i]],mpb[a[i]]));
            ans=max(ans,min(mpa[b[i]],mpb[b[i]]));
        }
        cout<<ans<<endl;
    }
}