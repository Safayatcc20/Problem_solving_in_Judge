#include<stdio.h>
int main(){
    long long int t,out,in,sum=0,max=0;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&out,&in);
        sum=sum+in-out;
        if(sum>max){
            max=sum;
        }

    }
    printf("%lld\n",max);
    return 0;
}
