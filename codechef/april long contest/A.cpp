#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main ()
{
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll a,b;
        cin>>a>>b;
        if(a>=b){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
