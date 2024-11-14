#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll t;
    cin>>t;
    while(t--){
        ll n,ans;
        cin>>n;
        if(n%2==0){
            ans=n/2-1;
            cout<<ans<<endl;
        }
        else{
            cout<<n/2<<endl;
        }
    }
}
