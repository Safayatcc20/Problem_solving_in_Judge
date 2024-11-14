//SOLVED DONE
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a,b=1,c=1,d=1;
        a=n-b-c-d;
        if(gcd(a,b)==lcm(c,d)){
            cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        }
    }
}
