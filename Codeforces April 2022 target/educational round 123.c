#include<stdio.h>
#include<math.h>
int main ()
{
    long long int t;
    scanf("%lld",&t);
    while(t--){
        long long int x,y;
        scanf("%lld%lld",&x,&y);
        if(x==0 & y==0){
            printf("0\n");
        }
        else{
                if(x%2==0 || y%2==0){
                    printf("1\n");
                }
                else{
                    printf("2\n");
                }
        }
    }

    return 0;
}
