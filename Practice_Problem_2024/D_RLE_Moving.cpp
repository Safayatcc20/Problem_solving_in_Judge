
/***** Bismillahir Rahmanir Rahim *****/

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

pair<int, int> equ(char c)
{
    if (c == 'U')
        return {-1, 0};
    if (c == 'D')
        return {1, 0};
    if (c == 'L')
        return {0, -1};
    if (c == 'R')
        return {0, 1};
    return {0, 0};
}
void solve()
{
    int rt, ct, ra, ca;
    cin >> rt >> ct >> ra >> ca;
    int n, m, l;
    cin >> n >> m >> l;

    vector<pair<char, int>> s(m);
    for (int i = 0; i < m; i++)
    {
        char c;
        int val;
        cin >> c >> val;
        s[i] = {c, val};
    }

    vector<pair<char, int>> t(l);
    for (int i = 0; i < l; i++)
    {
        char c;
        int val;
        cin >> c >> val;
        t[i] = {c, val};
    }

    int difr = rt - ra;
    int difc = ct - ca;
    int ans = 0;
    int i = 0, j = 0;

    while (i < m && j < l)
    {
        char tk = s[i].first, ak = t[j].first;
        int tv = s[i].second, av = t[j].second;

        int move = min(tv, av);
        auto dt = equ(tk);
        auto da = equ(ak); 

        int ndifr = dt.first - da.first;
        int ndifc = dt.second - da.second;

        if (ndifr == 0 && ndifc == 0)
        {
            if (difr == 0 && difc == 0)
            {
                ans += move;
            }
        }
        else if (ndifr == 0)
        {
            if (difr == 0 && ndifc != 0 && (-difc) % ndifc == 0)
            {
                int k = (-difc) / ndifc;
                if (k >= 1 && k <= move)
                    ans++;
            }
        }
        else if (ndifc == 0)
        {
            if (difc == 0 && ndifr != 0 && (-difr) % ndifr == 0)
            {
                int k = (-difr) / ndifr;
                if (k >= 1 && k <= move)
                    ans++;
            }
        }
        else
        {
            if ((-difr) % ndifr == 0 && (-difc) % ndifc == 0)
            {
                int k1 = (-difr) / ndifr;
                int k2 = (-difc) / ndifc;
                if (k1 == k2 && 1 <= k1 && k1 <= move)
                    ans++;
            }
        }

        difr += ndifr * move;
        difc += ndifc * move;

        tv -= move;
        av -= move;

        if (tv == 0)
            i++;
        else
            s[i].second = tv;
        if (av == 0)
            j++;
        else
            t[j].second = av;
    }

    cout << ans << '\n';
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