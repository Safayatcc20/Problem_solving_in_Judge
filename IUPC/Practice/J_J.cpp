/*
 **** Bismillahir Rahmanir Rahim ****
 */

#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define int long long
long long t = 1;
constexpr bool multiple_test_cases = 1;
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
const long long N = 10000;
long long prime[N];
long long fact(long long n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
long long findXor(long long n)
{ // reming: function calling findXor(sending value - 1);
    long long rest = n % 4;
    if (rest == 0)
        return n;
    if (rest == 1)
        return 1;
    if (rest == 2)
        return n + 1;
    if (rest == 3)
        return 0;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(14);
    for (int i = 0; i < 14; i++)
    {
        v[i] = i;
        if (i > 10)
            v[i] = 10;
    }
    map<int , int>mp;
    int john = 0;
    int x, y;
    cin >> x >> y;
    john += v[x] + v[y];
    mp[x]++;
    mp[y]++;
    int mary = 0;
    cin >> x >> y;
    mary += v[x] + v[y];
    mp[x]++;
    mp[y]++;
    for(int i = 0 ;i < n ;i++){
        int x ;
        cin >> x;
        john+=v[x];
        mary+=v[x];
        mp[x]++;
    }
    for(int i = 1; i<= 13; i++){
        if(mp[i] == 4) continue;
        if(mary + v[i] == 23 or (john + v[i] > 23 and mary + v[i] < 23)){
            cout << i << sad;
            return;
        }
    }
    cout << -1 << sad;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}