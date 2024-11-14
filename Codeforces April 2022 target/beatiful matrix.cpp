#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll a[5][5],temp,rem;
    for(ll i=0;i<5;i++){
        for(ll j=0;j<5;j++){
            cin>>a[i][j];
            if(a[i][j]==1){
                rem=i;
                temp=j;
            }
        }
    }
    cout<<abs(rem-2)+abs(temp-2)<<"\n";
    return 0;
}
