#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    ll len=s.length();
    while(t--){
        for(ll i=0;i<len;i++){
            if(s[i]=='B' && s[i+1]=='G'){
                s[i]='G';
                s[i+1]='B';
                i++;
            }
        }
    }
    cout<<s<<endl;
}
