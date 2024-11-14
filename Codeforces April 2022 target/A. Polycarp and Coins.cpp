#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long a, b;
        a = n / 3;
        if((n - a) % 2 == 0){
            b = (n - a) / 2 ;
            cout << a <<" " << b << "\n";
        }
        else {
            b = n / 3 ;
            a = (n - b) / 2 + 1;
            cout << a << " " << b << "\n";
        }
    }
}
