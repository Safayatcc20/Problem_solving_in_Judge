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
long long findXor(long long n){//reming: function calling findXor(sending value - 1);
    long long rest = n % 4;
    if(rest == 0) return n;
    if(rest == 1) return 1;
    if(rest == 2) return n+1;
    if(rest == 3) return 0;
}
// Linear Diophantine Equation ax + by = c;
//solution by using  Extended Euclidean algorithm one solution
int extgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
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
void solve(){
    int N;
    long long W;
    cin >> N >> W;

    vector<long long> weights(N);
    vector<int> values(N);
    int totalValue = 0;

    for (int i = 0; i < N; ++i) {
        cin >> weights[i] >> values[i];
        totalValue += values[i];
    }

    // DP array to store the minimum weight needed to achieve each possible value
    vector<long long> dp(totalValue + 1, LLONG_MAX);
    dp[0] = 0;  // Base case: 0 weight needed to achieve 0 value

    for (int i = 0; i < N; ++i) {
        for (int v = totalValue; v >= values[i]; --v) {
            if (dp[v - values[i]] != LLONG_MAX) {
                dp[v] = min(dp[v], dp[v - values[i]] + weights[i]);
            }
        }
    }

    // Print the DP table
    /* cout << "DP Table: (minimum weight for each value)" << endl;
    for (int v = 0; v <= totalValue; ++v) {
        if (dp[v] == LLONG_MAX) {
            cout << "Value " << v << ": INF" << endl;
        } else {
            cout << "Value " << v << ": " << dp[v] << endl;
        }
    } */

    // Find the maximum value that can be achieved within the weight limit W
    int maxAchievableValue = 0;
    for (int v = 0; v <= totalValue; ++v) {
        if (dp[v] <= W) {
            maxAchievableValue = v;
        }
    }

    //cout << "Maximum Achievable Value within weight limit " << W << ": " << maxAchievableValue << endl;
    cout << maxAchievableValue << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}