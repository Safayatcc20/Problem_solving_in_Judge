/*
 **** Bismillahir Rahmanir Rahim ****
 */

#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
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
// Linear Diophantine Equation ax + by = c;
// solution by using  Extended Euclidean algorithm one solution
int extgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
vector<pair<int, int>> pre;
bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return (a.second < b.second or a.second == b.second and a.first < b.first);
}
bool com(pair<int, int> &a, pair<int, int> &b)
{
    return (a.second > b.second or a.second == b.second and a.first < b.first);
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int ans = 0;
    int ft = 0;
    while (n)
    {

        vector<pair<int, int>> chk;
        for (int i = 0; i < pre.size(); i++)
        {
            if (ft == 0 and i == 0)
                continue;
            chk.push_back({i, n / pre[i].second});
        }
        ft = 1;
        sort(all(chk), com);
        if (n - chk[0].second * pre[chk[0].first].second >= 0)
        {
            n -= chk[0].second * pre[chk[0].first].second;
            v.push_back({pre[chk[0].first].first, chk[0].second});
        }
        else
        {
            for (int i = 0; i < chk.size(); i++)
            {
                if (n - chk[0].second * pre[chk[0].first].second >= 0)
                {
                    n -= chk[0].second * pre[chk[0].first].second;
                    v.push_back({pre[chk[0].first].first, chk[0].second});
                }
                if (n == 0)
                    break;
            }
        }
    }
    if (n)
    {
        vector<pair<int, int>> chk;
        for (int i = 0; i < pre.size(); i++)
        {
            if (ft == 0 and i == 0)
                continue;
            chk.push_back({pre[i].first, n / pre[i].second});
        }
        sort(all(chk), comp);
        if (n - chk[0].second > 0)
        {
            n -= chk[0].second;
            v.push_back({chk[0].first, chk[0].second});
        }
    }
    for (auto &x : v)
    {
        for (int i = 1; i <= x.second; i++)
        {
            cout << x.first;
        }
    }
    cout << sad;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    pre.push_back({0, 6});
    pre.push_back({1, 2});
    pre.push_back({2, 5});
    pre.push_back({3, 5});
    pre.push_back({4, 4});
    pre.push_back({5, 5});
    pre.push_back({6, 6});
    pre.push_back({7, 3});
    pre.push_back({8, 7});
    pre.push_back({9, 6});
    sort(all(pre), comp);
    cin >> t;
    while (t--)
    {
        solve();
    }
}