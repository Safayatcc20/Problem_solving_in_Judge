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
const long long N = 10000;
long long prime[N];
void seive()
{
    prime[0] = prime[1] = 1;
    for (long long i = 2; i * i <= N; i++)
    {
        if (!prime)
        {
            for (long long j = i * i; j <= N; j += i)
            {
                prime[j] = 1;
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    char ch;
    cin >> ch;
    string s;
    cin >> s;
    if (ch == 'g')
    {
        cout << 0 << sad;
        return;
    }
    s += s;
    int ans = 0;
    int j = 0;
    int repeat = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (s[i] == ch)
        {
            int cnt = 0;
            if (repeat == 1)
            {
                cnt++;
            }
            while (s[i] != 'g')
            {
                cnt++;
                i++;
                if (i == 2 * n)
                {
                    break;
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << sad;
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