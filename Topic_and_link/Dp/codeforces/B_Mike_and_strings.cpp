
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
// if c % gcd( a , b)  == 0 then solution exist otherwise not
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
// Euler totient function for single call
int phi(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans /= i;
            ans *= (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        ans /= n, ans *= (n - 1);
    return ans;
}
// Euler totient preprocessing(from 1 to n ) in O(nloglog(n))
vector<int> phai(1e7 + 10);
void init()
{
    // here check the problem requirement
    int maxn = 1e7 + 10;
    for (int i = 1; i <= maxn; i++)
    {
        phai[i] = i;
    }
    for (int i = 2; i <= maxn; i++)
    {
        if (phai[i] == i)
        {
            for (int j = i; j <= maxn; j += i)
            {
                phai[j] /= i;
                phai[j] *= (i - 1);
            }
        }
    }
    // here is the prefix sum of phai function
    // for(int i = 1; i <= maxn; i++){
    //     phai[i] += phai[i-1];
    // }
}
const int MOD = 1e9 + 7;
const int BASE = 31;
// Function to calculate hash value of a substring
int getHash(string &s , int m)
{
    long long hashValue = 0;
    for (int i = 0; i < m; i++)
    {
        hashValue = (hashValue * BASE + (s[i] - 'a' + 1)) % MOD;
    }
    return hashValue;
}
void solve()
{
    //dp + hashing
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &x : v)
    {
        cin >> x;
    }
    int m = v[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 1e18));
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = i;
    }
    vector<long long> power(m + 1);
    // Precompute powers of BASE up to m
    power[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        power[i] = (power[i - 1] * BASE) % MOD;
    }


    // Precompute hash values for all substrings of length m for each string
    vector<vector<long long>> hash_values(n, vector<long long>(m));
    for (int i = 0; i < n; i++)
    {
        string doubled = v[i] + v[i];  // Double the string for rotations
        long long hashValue = getHash(doubled, m);  // Initial hash of the first rotation
        hash_values[i][0] = hashValue;

        for (int j = 1; j < m; j++)
        {
            // Use rolling hash to compute hash of each rotation
            hashValue = (hashValue * BASE - (doubled[j - 1] - 'a' + 1) * power[m] % MOD + MOD) % MOD;
            hashValue = (hashValue + (doubled[j + m - 1] - 'a' + 1)) % MOD;
            hash_values[i][j] = hashValue;
        }
    }
    for (int i = 0; i < n; i++)
    {
        v[i] += v[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (hash_values[i][j] == hash_values[i - 1][k])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + j);
                }
            }
        }
    }

    int ans = 1e18;
    for (int i = 0; i < m; i++)
    {
        ans = min(ans, dp[n - 1][i]);
    }
    if (ans == 1e18)
        ans = -1;
    cout << ans << sad;
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