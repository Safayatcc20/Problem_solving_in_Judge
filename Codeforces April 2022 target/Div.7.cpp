#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int t,n,i,a;

    scanf("%d",&t);

    for(a=1;a<=t;a++) {
        scanf("%d",&n);
        int x = n % 10;
        int y = n+10;
        if(n%7==0){
            printf("%d \n", n);
        }
        else{
            for (i=(n - x); i<= (y - x); i++){
                if(i%7 == 0 && i%10 != 0){
                   printf("%d \n", i);
                }
            }
        }
    }
    return 0;
}
