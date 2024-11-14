#include<stdio.h>
int main(int argc, char *argv[])
{
	long long int t,a,b,ans,i;
	scanf("%lld",&t);
	while(t--){
	    scanf("%lld%lld",&a,&b);
	    if(a==0 && b==0){
	        printf("0\n");
	    }
	    else{
	        for(i=1;i<100;i++){
	            if(a*a+b*b==i*i){
	                ans=1;
	                break;
	            }
	            else{
	                ans=2;
	            }
	        }
	        printf("%lld\n",ans);
	    }
	}

}
