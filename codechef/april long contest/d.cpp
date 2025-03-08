#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
	ll t;
	cin>>t;
	while(t--){
    	ll a,b,i,j,x;
    	cin>>a>>b;
    	ll m,n,p;
    	for(i=a;i<b;i++){

            for(j=a+1;j<=b;j++){
                x=gcd(i,j-i);
        	    if(x>1){
        	        m=i,n=j,p=x;
        	        break;
        	    }
        	    else{
        	        p=0;
        	    }
            }
            if(p>1){
                m=i,n=j,p=x;
                break;
            }
    	}
    	if(p>1){
    	    cout<<m<<" "<<n<<endl;
    	}
    	else{
    	    cout<<"-1"<<endl;
    	}
	}
	return 0;
}

