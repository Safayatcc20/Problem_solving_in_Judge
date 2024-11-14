#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll t;
    cin>>t;
    while(t--){
        ll x,a,b,c,y,z;
        cin>>x>>y>>z;
        if(x<=z){
            a=x;
        }
        else{
            a=0;
        }
        if(x>y){
            b=y;
        }
        else{
            b=x;
        }
        if(y==z){
            c=z;
        }
        else{
            if(a>b){
                c=a-b;
            }
            else{
                c=b-a;
            }
        }
        if(a==0 || b==0||c==0){
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
    }
}
