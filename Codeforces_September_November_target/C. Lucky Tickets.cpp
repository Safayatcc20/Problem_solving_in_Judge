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
long long fact(long long n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
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
    long long n;
    cin >> n;
    vector<long long> v(n);
    map<long long, long long> mp;
    long long cnt = 0;
    for (auto &x : v)
        cin >> x;
    for (long long i = 0; i < n; i++)
    {
        if (mp[v[i]] == 0)
        {
            mp[v[i]] = 1;
            long long ans = v[i], out = v[i];
            for (long long j = i + 1; j < n; j++)
            {
                if (mp[v[j]] == 0)
                {
                    long long take = v[j], outer = v[j];
                    vector<long long> vv;
                    while (take > 0)
                    {
                        vv.push_back(take % 10);
                        take /= 10;
                    }
                    reverse(all(vv));
                    for (long long h = 0; i < vv.size(); h++)
                    {
                        ans = ans * 10 + vv[h];
                    }
                    vv.clear();
                    cout << ans << " " << ans % 3 << sad;
                    if (ans % 3 == 0)
                    {
                        cnt++;
                        mp[v[j]] = 1;
                        break;
                    }
                    else
                    {
                        while (out > 0)
                        {
                            /* code */
                            vv.push_back(out % 10);
                            out /= 10;
                        }
                        reverse(all(vv));
                        for (long long k = 0; i < vv.size(); k++)
                        {
                            outer = outer * 10 + vv[k];
                        }
                        vv.clear();
                        cout << outer << " " << outer % 3 << sad;
                        if (outer % 3 == 0)
                        {
                            cnt++;
                            mp[v[j]] = 1;
                            cnt++;
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
            }
        }
    }
    cout << cnt << sad;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // long long t;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}