#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> num;
int dp[20][20][20][2][2];

// pos = current position
// last = last digit used in subsequence (-1 initially)
// len = remaining length to pick
// tight = whether current prefix matches num
// leadingzero = have we started the number yet
int call(int pos, int last, int len, bool tight, bool leadingzero) {
    if(pos == num.size()) return len == 0;

    if(dp[pos][last+1][len][tight][leadingzero] != -1)
        return dp[pos][last+1][len][tight][leadingzero];

    int res = 0;
    int limit = tight ? 9 : num[pos];

    for(int d = 0; d <= limit; d++) {
        bool ntight = tight or (d < limit);
        bool nstart = leadingzero || d != 0;

        // Option 1: skip this digit
        res += call(pos+1, last, len, ntight, nstart);

        // Option 2: take this digit in subsequence if valid
        if(nstart && d > last && len > 0) {
            res += call(pos+1, d, len-1, ntight, true);
        }
    }

    return dp[pos][last+1][len][tight][leadingzero] = res;
}

int solve(int x, int len) {
    if(x < 0) return 0; // for a-1
    if(x == 0) return (len == 0 ? 1 : 0);

    num.clear();
    while(x > 0) {
        num.push_back(x % 10);
        x /= 10;
    }
    reverse(num.begin(), num.end());

    memset(dp, -1, sizeof(dp));
    return call(0, -1, len, false, false);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for(int caseNo = 1; caseNo <= t; caseNo++) {
        int a, b;
        cin >> a >> b;
        cout << "Case " << caseNo << ": ";

        for(int len = 9; len >= 1; len--) {
            int cnt = solve(b, len) - solve(a-1, len);
            if(cnt > 0) {
                cout << len << " " << cnt << "\n";
                break;
            }
        }
    }
    return 0;
}
