#include<stdio.h>
int main ()
{
    long long int n,i,j,count=0,r;
    scanf("%lld",&n);
    for(i=2;i<n;i++)
    {
        for(j=2;j<=i;i++)
        {
            if(j%i==0)
            {
                count++;
            }
        }
        if(count==1)
        {
            r=j;
        }
        else{
            continue;
        }
    }
    printf("%lld ",j);

}
