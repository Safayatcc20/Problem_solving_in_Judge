#include<iostream>

using namespace std;
int main()
{
    long long int n,k,i,sum,ans=0;
    scanf("%lld%lld",&n,&k);
    for(i=1;i<=k;i++){
        if(n%10==0){
            ans=n/10;
            n=n/10;
        }
        else{
            ans=n-1;
            n=n-1;
        }
    }
    printf("%lld\n",ans);
}

