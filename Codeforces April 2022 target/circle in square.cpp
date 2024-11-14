#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pi 2*acos(0.0)
int main ()
{
    ll t;
    cin>>t;
    for(ll i=1;i<=t;i++)
    {
        double r;
        cin>>r;
        double a=r*2;
        double ans=a*a-(pi)*r*r;
        cout<<"Case i: "<<fixed<<setprecision(2)<<ans<<endl;
    }
}

