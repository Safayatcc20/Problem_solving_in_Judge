#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        long long n , m , a , b;
        cin >> n >> m;
        a = max(n , m );
        b = min (n , m);
        n = a, m = b;
        if( n > 2 && m == 1){
            cout << - 1 << "\n";
        }
        else {
            if(( n + m ) % 2 == 0){
                cout << 2 * n - 2 << "\n";
            }
            else{
                cout << 2 * n - 3 << "\n";
            }
        }
    }
}
