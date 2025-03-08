#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    /*sort(a,a+n);
    ll m;
    ll b[n],mx=a[0],cnt=0;
    for(ll i=0;i<n;i++){
        m=max(m,a[i]);
        if(mx!=a[i]){
            mx=a[i];
            b[i]=mx;
            if(b[i]!=m){
                cnt++;
            }
        }
    }*/
    if(n%2==0){
        cout<<n/2<<endl;
    }
    else {
        cout<<0<<endl;
    }
}
