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
    long long n, k;
    cin >> n >> k;
    deque<long long> q;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        q.push_back(x);
    }
    long long win = 0, cnt = 0;
    while (q.size() > 1)
    {
        long long ft = q.front();
        q.pop_front();
        long long sec = q.front();
        q.pop_front();
        q.push_front(max(sec, ft));
        long long winner = max(sec, ft);
        if (winner > win)
        {
            win = winner;
            cnt = 1;
        }
        else
        {
            cnt++;
            if (cnt == k)
            {
                break;
            }
        }
    }
    cout << win << sad;
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