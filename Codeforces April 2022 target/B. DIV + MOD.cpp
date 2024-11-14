#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while(t--){
        long long l, r, a;
        cin >> l >> r >> a;
        if(a == 1){
            cout << r << "\n";
        }
        else if( r % a +1 == a){
            cout << r % a + r / a << "\n";
        }
        else if( l / a == r / a){
            cout << r % a + r /a << "\n";
        }
        else{
            cout << r / a + a - 2 << "\n";
        }
    }

    return 0;
}
