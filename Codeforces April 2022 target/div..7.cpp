#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int t,n,a;

    scanf("%d",&t);

    for(a=1;a<=t;a++) {
        scanf("%d",&n);
        int x = n % 7;
        int y = 7-x;
        int z = n % 10;

        if(n%7==0){
            printf("%d \n", n);
        }

        else if(y+z<10){
            n +=y;
            printf("%d \n", n);
        }

        else{
            n -=x;
            printf("%d \n", n);
        }
    }
    return 0;
}
