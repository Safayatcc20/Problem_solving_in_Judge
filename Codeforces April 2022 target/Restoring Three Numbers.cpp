#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll x1,x2,x3,x4;
    cin>>x1>>x2>>x3>>x4;
    ll a[4];
    a[0]=x1,a[1]=x2,a[2]=x3,a[3]=x4;
    sort(a,a+4);
    if(x4-x1<0){
        ll x,y,z;
        z=a[3]-a[0];
        y=a[3]-a[1];
        x=a[3]-a[2];
        cout<<x<<" "<<y<<" "<<z<<endl;
    }
    else{
        ll x,y,z;
        z=a[3]-a[0];
        y=a[3]-a[2];
        x=a[3]-a[1];
        cout<<x<<" "<<y<<" "<<z<<endl;
    }
}
