#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll n;
    ll ans=-1,cnt=0;
    cin>>n;
    while(n--){
        ll a;
        cin>>a;
        if(ans==a){
            cnt++;
        }
        else if(a>=10){
            cnt=a-10;
        }
        else{
            ans=a;
            cnt=0;
        }
        if(cnt==0){
            cout<<a<<" "<<0<<endl;
        }
        else{
            cout<<a-cnt<<" "<<cnt<<endl;
        }
    }
}
