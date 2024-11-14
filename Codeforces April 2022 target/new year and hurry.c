#include<stdio.h>
typedef long long int ll;
int main ()
{
    ll n,k,count=0;
    ll ans=0;
    scanf("%lld%lld",&n,&k);
    for(ll i=1;i<=n;i++){
        ans=ans+i*5;
        if(1200+k+ans<=1440){
            count++;
        }
    }
    printf("%lld",count);
}
