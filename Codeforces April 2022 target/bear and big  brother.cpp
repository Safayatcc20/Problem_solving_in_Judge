#include<iostream>

using namespace std;
int main()
{
    long long int a,b,i,sum,ans;
    scanf("%lld%lld",&a,&b);
    for(i=1;;i++){
        sum=a*3;
        a=a*3;
        ans=b*2;
        b=b*2;
        if(sum>ans){
            printf("%lld\n",i);
            break;
        }
    }
}

