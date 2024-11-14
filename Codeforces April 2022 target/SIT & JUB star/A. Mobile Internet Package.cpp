#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long a, b , c , d;
    cin >> a >> b >> c >> d;
    if( d > a){
        cout << b + (d - a) * c << "\n";
    }
    else{
        cout << b << "\n";
    }
}
