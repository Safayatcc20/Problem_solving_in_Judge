#include <iostream>
using namespace std;

int main() {
	long long t;
	cin >> t;
	while(t-- ){
	    long long n, x;
	    cin >> n >> x;
	    float a[n], sum = 0, ans = 0;
	    for(long long i= 0; i < n-1; i++){
	        cin >> a[i];
	        sum = sum + (a[i]);
	    }
	    ans = x - (sum / n);
	    if(ans >= 0){
	        cout << ans * n << "\n";
	    }
	    else {
	        cout << 0 << "\n";
	    }
	}
	return 0;
}
