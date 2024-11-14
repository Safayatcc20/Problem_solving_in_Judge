#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k , l , c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    long long ans, x, y, z;
    x = (k * l) / nl;
    y = c * d;
    z = p / np;
    ans = min (x, y);
    cout << min(ans,z)/n << "\n";
}
