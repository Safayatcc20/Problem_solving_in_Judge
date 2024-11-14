#include<stdio.h>
#include<math.h>
int main ()
{
    long long int t,n;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        long long int a[n],i,j,k,temp;
        for(i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(a[i]<a[j]){
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
        printf("%lld",a[n-1]+a[n-2]);
    }

}
