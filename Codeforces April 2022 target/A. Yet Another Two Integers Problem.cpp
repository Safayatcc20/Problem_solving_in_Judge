#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        long long a, b;
        cin >> a >> b;
        if ( a == b ){
            cout << 0 << "\n";
        }
        else if( a > b ){
            long long sub;
            sub = a - b;
            if( sub % 10 == 0){
                cout << sub / 10 << "\n";
            }
            else{
                cout << (sub / 10) + 1 << "\n";
            }
        }
        else {
            long long sub;
            sub = b - a;
            if( sub % 10 == 0){
                cout << sub / 10 << "\n";
            }
            else{
                cout << (sub / 10) + 1 << "\n";
            }
        }
    }
}
