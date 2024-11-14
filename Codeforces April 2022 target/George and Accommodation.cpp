#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll t;
    cin>>t;
    ll p,q,cnt=0;
    while(t--){
        cin>>p>>q;
        if(q-p>=2){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

