#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    char s[100],m=0;
    scanf("%s",s);
    int len=strlen(s),x=0;
    for(int i=0;i<len;i++){
        sort(s,s+len);
        if(s[i]>='a' && s[i]<='z'){
            if(s[i]!=m){
                m=s[i];
                x++;
            }
        }
    }
    if(x%2==0){
        printf("CHAT WITH HER!");
    }
    else{
        printf("IGNORE HIM!");
    }
    return 0;
}
