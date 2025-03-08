# include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll t;
    cin>>t;
    for(ll i=1;i<=t;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        if(a*a==b*b+c*c ||b*b==a*a+c*c||a*a+b*b==c*c){
            cout<<"Case "<<i<<": "<<"yes"<<endl;
        }
        else{
            cout<<"Case "<<i<<": "<<"no"<<endl;
        }
    }
}
