#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll n;
    cin>>n;
    while(n--){
        ll a;
        ll ans=0,cnt=0;
        cin>>a;
        if(ans!=a){
            ans=a;
            cout<<"0 "<<a<<endl;
        }
        else{
            cnt++;
            cout<<cnt<<" "<<a-cnt<<endl;
        }
    }
}
