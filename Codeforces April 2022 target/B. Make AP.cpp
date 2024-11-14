#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long a, b, c, r1, r2;
    cin >> a >> b >> c;
    long long x , y, z;
    x = b -(c - b);
    if( x >= a && x % a == 0 && x != 0){
        cout << "YES\n";
        return ;
    }
    y = a + (c - a) / 2;
    if(y >= b && (c - a) % 2 == 0 && y % b ==0 && y != 0 ){
        cout << "YES\n";
        return ;
    }
    z = a + 2 * (b - a);
    if(z >= c && z % c == 0 && z != 0){
        cout << "YES\n";
        return ;
    }
    cout << "NO\n";
}
int main()
{
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
