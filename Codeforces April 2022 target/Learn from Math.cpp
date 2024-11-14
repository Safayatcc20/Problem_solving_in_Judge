

#include<bits/stdc++.h>
typedef long long int ll;

using namespace std;

int main (){
    ll n,x,y,i;
    cin>>n;
    if(n%2==0){
        x=4;
        y=n-x;
        for(i=2;;i++){
            if(x%i==0){
                if(y%i==0){
                    printf("%lld %lld",x,y);
                    break;
                }
            }

        }
    }
    else{
        x=9;
        y=n-9;
        printf("%lld %lld",x,y);
    }
}

