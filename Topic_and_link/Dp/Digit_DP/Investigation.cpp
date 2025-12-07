/// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x?

#include <bits/stdc++.h>
using namespace std;

vector<int> num;
int a, b, d, k;
map<tuple<int, int, int,bool>, int> dp;
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

long long call(int pos, int remNum, int remSum, bool tight)
{
    if (pos == (int)num.size())
    {
        return (remNum  == 0 && remSum == 0);
    }

    auto key = make_tuple(pos, remNum, remSum, tight);
    if (dp.count(key))
        return dp[key];

    int limit = tight ? (num[pos] ) : 9;
    long long res = 0;
    for (int dgt = 0; dgt <= limit; dgt++)
    {
        int nRemNum = (remNum * 10 + dgt) % d;
        int nRemSum = (remSum + dgt) % d;
         bool ntight = tight && (dgt == limit);

        res += call(pos + 1, nRemNum, nRemSum, ntight);
    }
    return dp[key] = res;
}

int solve(int b)
{
    num.clear();
    while (b > 0)
    {
        num.push_back(b % 10);
        b /= 10;
    }
    reverse(num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity

    dp.clear();
    int res = call(0, 0, 0, true);
    return res;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cin >> a >> b >> d;
        int res = solve(b) - solve(a - 1);
        cout << "Case "<< i <<  ": ";
        cout << res << endl;
    }
    return 0;
}