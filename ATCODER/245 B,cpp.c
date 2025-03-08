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
    sort(a,a+n);
    ll b[n];
    for(ll i=0;i<n;i++){
        if(a[i]!=a[i+1]){
            b[i]=a[i];
        }
    }
    for(ll i=0;i<n;i++){
        cout<<b[i];
    }
}
