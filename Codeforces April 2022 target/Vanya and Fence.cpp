#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll n,h;
    cin>>n>>h;
    ll a[n];
    ll cnt=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>h){
            cnt+=2;
        }
        else{
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
