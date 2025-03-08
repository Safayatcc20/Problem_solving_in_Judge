#include <bits/stdc++.h>
typedef long long int ll;

int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a==0 && b==0){
        printf("Takahashi\n");
    }
    else if(c==0 && d==0){
        printf("Aoki\n");
    }
    else{
        if(a==c){
          if(b<=d){
            printf("Takahashi\n");
          }
          else{
            printf("Aoki\n");
          }
        }
        else if(a>c){
            printf("Aoki\n");
        }
        else{
            printf("Takahashi\n");
        }
    }

    return 0;
}

