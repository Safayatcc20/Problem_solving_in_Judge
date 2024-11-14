#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll t;
    cin>> t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        if(a%b==0){
            cout<<"0"<<endl;
        }
        else{
            ll ans;
            ans=a%b;
            ll rem=b-ans;
            cout<<rem<<endl;
        }
    }
}
