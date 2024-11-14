//solved
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        for(long long i = 2; i <= n; i++){
            if( n % (llround(pow(2 , i)-1)) == 0){
                cout << n / (llround(pow(2 , i)-1)) << "\n";
                break;
            }
        }
    }
}
