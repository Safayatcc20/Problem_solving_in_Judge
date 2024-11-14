#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll n,friends;
    cin>>n;
    ll a[105];
    for (ll i=1;i<=n;i++){
        cin>>friends;
        a[friends]=i;
    }
    for (ll i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
}
