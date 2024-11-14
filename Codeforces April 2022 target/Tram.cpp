#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll n,mx=0,in,out,sum=0;
    cin>>n;
    while(n--){
        cin>>out>>in;
        sum=sum+in-out;
        if(mx<sum){
            mx=sum;
        }
    }
    cout<<mx<<endl;
    return 0;
}
