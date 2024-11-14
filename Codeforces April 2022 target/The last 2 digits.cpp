#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans1,x,y,ans,res,res1;
    ans=a*b;
    ans1=c*d;
    x=ans%100;
    y=ans1%100;
    res=(x*y)%10;
    res1=((x*y)/10)%10;
    cout<<res*1+res1*10<<endl;
}
