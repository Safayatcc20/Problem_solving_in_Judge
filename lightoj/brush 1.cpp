# include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll t;
    cin>>t;
    for(ll i=1;i<=t;i++){
        ll a,sum=0;
        cin>>a;
        ll b[a];
        for(ll i=0;i<a;i++){
            cin>>b[i];
        }
        for(ll i=0;i<a;i++){
            if(b[i]>=0){
                sum=sum+b[i];
            }
        }
        cout<<"Case "<<i<<": "<<sum<<endl;
        sum=0;
    }
}
