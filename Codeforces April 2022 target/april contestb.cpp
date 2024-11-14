/*#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    /*ll n;
    cin>>n;
    ll ans=0;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        ans=ans+a[i];
    }
    cout<<ans;*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll r,ans=0;
    cin>>r;
    ll a[3000];
    for(ll j=0,i=-45;i<=2999;j++,i++){
        ans=ans+i;
        a[j]=ans;
        cout<<a[j]<<" 3";
    }
    return 0;
}
