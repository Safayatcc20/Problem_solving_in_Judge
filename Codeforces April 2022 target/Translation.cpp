#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    string s1,s2;
    cin>>s1>>s2;
    ll cnt=0;
        ll len=s1.length();
    for(ll i=0,j=len-1;i<s1.length(),j>=0;i++,j--){
            if(s1[i]==s2[j]){
                cnt++;
            }
    }
    if(cnt==len){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
