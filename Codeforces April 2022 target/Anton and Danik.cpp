#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll n;
    cin>>n;
    string s;
    cin >>s;
    ll anton=0,danik=0;
    for(ll i=0;i<s.length();i++){
        if(s[i]=='A'){
            anton++;
        }
        else{
            danik++;
        }
    }
    if(anton <danik){
        cout<<"Danik"<<endl;
    }
    else if(anton ==danik){
        cout<<"Friendship"<<endl;
    }
    else{
        cout<<"Anton"<<endl;
    }
}
