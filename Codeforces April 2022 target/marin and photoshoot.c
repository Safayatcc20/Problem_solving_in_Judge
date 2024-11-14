#include<stdio.h>
typedef long long int ll;
int main ()
{
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll n,i,j,count=0,count1=0;
        scanf("%lld",&n);
        char s[n];
        scanf("%s",s);
        for(i=0;i<n;i++){
            if(s[i]=='0'){
                count++;

            }
            else{
                count1++;
            }
        }
        if(count1>count){
            printf("0\n");
        }
        else{
            for(i=0;i<n;i++){
                if(s[i]=='0'){

                }
            }
        }
    }
}
