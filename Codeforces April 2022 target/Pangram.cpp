
 //::UNSOLVED::

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll len =s.length(),cnt=0;
    for(ll i=0;i<len;i++){
        if((s[i])=='a' &&(s[i])=='z'){
            cnt++;
        }
        else if(s[i]=='A' && s[i]=='B'){
            cnt++;
        }
    }
    if(cnt>=26){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
