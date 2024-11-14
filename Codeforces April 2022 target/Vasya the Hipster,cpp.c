
#include<bits/stdc++.h>
typedef long long int ll;

using namespace std;

int main (){
    ll a,b,i;
    cin>>a>>b;
    if(a>b){
        cout<<b<<" ";
        if((a-b)%2==0){
            cout<<(a-b)/2<<endl;
        }
        else{
            cout<<(a-b)/2;
        }
    }
    else{
        cout<<a<<" ";
        if((b-a)%2==0){
            cout<<(b-a)/2<<endl;
        }
        else{
            cout<<(b-a)/2;
        }
    }
}
