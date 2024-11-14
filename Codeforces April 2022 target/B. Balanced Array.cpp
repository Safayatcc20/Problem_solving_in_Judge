#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        if((n / 2) % 2 != 0){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" << "\n";
            long long sum1 = 0, sum2 = 0;
            for(long long i = 1; i <= n/2 ; i++){
                cout << i * 2 << " ";
                sum1 += i * 2;
            }
            for(long long i = 1; i < n/2 ; i++){
                cout << 2 * i - 1 << " ";
                sum2 +=  2 * i - 1;
            }
            cout << sum1 - sum2 << "\n";
        }
    }
}
