#include<stdio.h>
#include<math.h>
int main(){
    long long int t,i;
    scanf("%lld",&t);
    for(i=0;i<t;i++){
        long long int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        long long int d=abs(a-b);
        long long int x=d*2;
        if(a>x||b>x||c>x){
            printf("-1\n");
        }
        else if(c+d<=x){
            printf("%lld\n",(c+d));
        }
        else if(c-d>0){
            printf("%lld\n",c-d);
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}
