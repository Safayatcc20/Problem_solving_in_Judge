#include<stdio.h>
typedef long long int ll;
int main()
{
    ll count=0,n;
    scanf("%lld",&n);
    ll a[n],b[n];
    for(ll i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(ll i=1;i<n;i++){
        scanf("%lld",&b[i]);
    }
    for(ll i=0;i<n;i++){
        if(a[i]==n || b[i]==n){
            count++;
        }
    }
    if(count==0){
        printf("Oh, my keyboard!\n");
    }
    else{
        printf("I become the guy.\n");
    }
    return 0;
}
