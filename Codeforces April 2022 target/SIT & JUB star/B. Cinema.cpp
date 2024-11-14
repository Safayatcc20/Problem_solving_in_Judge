#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long a, b , c , d;
    cin >> a >> b >> c >> d;
    if( c > a && c < b){
        if(c+d >= a+b){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" << "\n";
        }
    }
    else if( d > b && d < a){
        if(c+d >= a + b){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" << "\n";
        }
    }
    else if( (c <= a || c <= b) && (d <= a || d <= b))
    {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << '\n';
    }
}
