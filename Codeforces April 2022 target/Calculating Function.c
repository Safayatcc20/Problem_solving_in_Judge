#include<stdio.h>
#include<math.h>
int main(){
    long long int n,sum=0;
    scanf("%lld",&n);
    if(n%2==0){
        printf("%lld\n",(n/2));
    }
    else{
        printf("-%lld\n",(n+1)/2);
    }
}
