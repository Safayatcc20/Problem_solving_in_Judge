#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll n,cnt=0;
    cin>>n;
    ll mx[100000];
    for(ll i=0;i<n;i++){
        cin>>mx[i];
    }
    for(ll i=0;i<n;i++){
        if(mx[i]!=mx[i+1]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
