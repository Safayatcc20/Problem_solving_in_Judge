#include <iostream>
using namespace std;

int main() {
	long long t;
	cin >> t;
	while(t-- ){
	    long long n;
	    cin >> n ;
	    long long a[n], cnt = 0;
	        long long m = 0;
	        long long p = 0;
	    for(long long i= 0; i < n; i++){
	        cin >> a[i];
	        if(a[i] < 0){
	           cnt += m;
	            m++;
	        }
	        else if(a[i] > 0){
	            cnt += p;
	            p++;
	        }
	    }


	    cout << cnt << "\n";
	}
	return 0;
}
