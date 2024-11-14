/*
 **** Bismillahir Rahmanir Rahim ****
 */

#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
long long t = 1;
long long gcd(long long x, long long y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
long long lcm(long long x, long long y)
{
    return ((x * y) / gcd(x, y));
}
void solve()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (auto &x : v)
    {
        cin >> x;
    }
    bool flag = true;
    for(long long i = 1; i < n -1; i++){
        if(v[i] % gcd(v[i-1] , v[i+1])){
            flag = false;
            break;
        }
    }
    if(flag ){
        ha;
    }
    else{
        na;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}