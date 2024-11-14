#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n;
    cin >> n;
    long long cnt = 0, a, b, c, d, e;
    a = n / 100;
    b = (n % 100 ) / 20;
    c = ( (n % 100 ) % 20 ) / 10 ;
    d = (((n % 100) % 20 ) % 10 ) / 5;
    e = (((n % 100) % 20 ) % 10 ) % 5;
    cout << a + b + c + d + e << "\n";
}
