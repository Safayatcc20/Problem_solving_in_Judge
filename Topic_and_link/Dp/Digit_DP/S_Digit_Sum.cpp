/// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x?

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> num;
int a, b, d, k;
string val;
vector<vector<vector<int>>> dp;
const int mod = 1e9 + 7;
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

long long call(int pos, int remSum, bool tight, bool leading_zero)
{
    if (pos == (int)num.size())
    {
        return (remSum == 0 and leading_zero);
    }
    if (dp[pos][remSum][tight] != -1)
        return dp[pos][remSum][tight]%mod;

    int limit ;
    if(tight) limit = 9;
    else limit = num[pos]; 
    long long res = 0;
    for (int dgt = 0; dgt <= limit; dgt++)
    {
        // int nRemNum = (remNum * 10 + dgt) % b;
        int nRemSum = (remSum + dgt) % d;
        bool ntight = tight;
        bool nleading = leading_zero;
        if(tight == 0 and dgt < limit) ntight = 1;
        if(dgt == 0 and leading_zero) nleading = 1;
        res =(res+ call(pos + 1, nRemSum, ntight, nleading))%mod;
        res = res % mod;
    }
    return dp[pos][remSum][tight]  = res%mod;
}

int solve(string b)
{
    num.clear();
    for(auto &x:b)
    {
        num.push_back(x - '0');
    }
    // reverse(num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity

    dp.assign(num.size(), vector<vector<int>>(d, vector<int>(2, -1)));
    int res = call(0, 0, false, true)% mod;
    return res%mod;
}

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cin >> val ;
        cin >> d;
        
        int res = solve(val);
        // cout << "Case "<< i <<  ": ";
        cout << (res-1 +mod)%mod<< endl;
    }
    return 0;
}