#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main ()
{
    char s1[1000],s2[1000];
    scanf("%s%s",s1,s2);
    int len=strlen(s1);
    char m[1000],n[1000];
    for(int i=0;i<len;i++)
    {
        m[i]=tolower(s1[i]);
        n[i]=tolower(s2[i]);
    }
    int count=0;
    for(int i=0;i<len;i++)
    {
        if(m[i]>n[i])
        {
            printf("1");
            return 0;
        }
        else if(m[i]<n[i])
        {
            printf("-1");
            return 0;
        }
    }
    printf("0");
    return 0;
}
