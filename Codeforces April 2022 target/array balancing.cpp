#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n;
        cin >> n;
        long long a[n], b[n];
        for(long long i=0; i < n; i++){
            cin >> a[i];
        }

        for(long long i=0; i < n; i++){
            cin >> b[i];
        }

        long long j=0;

        for(long long i=0; i< n ; i++){
                if (a[i] > b[i]){
                   long long temp = a[i+j];
                    a[i+j]=b[i+j];
                    b[i+j]=temp;
                }
        }

        long long sum=0;
        for(long long i=0; i < n-1; i+=1){
            sum = sum + abs(a[i] - a[i+1]) + abs(b[i] - b[i+1]);;
        }

        cout << sum<< "\n";
    }
    return 0;
}
