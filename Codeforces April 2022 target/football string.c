#include <stdio.h>
#include<string.h>
int main()
{
    char s[100];
    scanf("%s",s);
    int i,len=strlen(s),count=0;
    for(i=0;i<len;i++){
        if(s[i]==s[i+1]){
            count++;
            if(count>=6){
                printf("YES");
                return 0;
            }
        }
        else{
            count=0;
        }
    }
    printf("NO");

    return 0;
}

