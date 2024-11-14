
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll x,sum=0;
        scanf("%lld",&x);
        ll a[x];
        for(ll i=0;i<x;i++){
            scanf("%lld",&a[i]);
        }
        if(x==1){
            if(a[0]==1){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
        else{
            /*for(ll i=0;i<x;i++){
                for(ll j=0;j<x;j++){
                    if(a[i]<a[j]){
                       ll temp=a[i];
                        a[i]=a[j];
                        a[j]=temp;
                    }
                }
            }*/
            sort(a,a+x);
            if(a[x-1]<a[x-2]+2){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
    return 0;
}
