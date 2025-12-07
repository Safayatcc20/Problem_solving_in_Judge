#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

int modpow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int modinv(int a) {
    return modpow(a, MOD - 2);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> start(m + 2), end(m + 2);

    vector<int> inv_q(n), prob(n); // prob[i] = p * q^(-1) % MOD
    for (int i = 0; i < n; i++) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        int inv = modinv(q);
        prob[i] = p * inv % MOD;
        start[l].emplace_back(i, prob[i]);
        end[r + 1].emplace_back(i, prob[i]);
    }

    vector<int> prob_coverage(m + 2, 0); // probability that a cell is covered exactly once
    vector<int> dp(m + 2, 0);
    dp[0] = 1;

    for (int i = 1; i <= m; i++) {
        // we simulate the events
        // Instead of segment tree, we use current sum of probabilities
        for (auto &x : start[i]) {
            prob_coverage[i] = (prob_coverage[i] + x.second) % MOD;
        }
        for (auto &x : end[i]) {
            prob_coverage[i] = (prob_coverage[i] - x.second + MOD) % MOD;
        }

        // At cell i, total probability that exactly 1 segment covers it = prob_coverage[i]
        dp[i] = dp[i - 1] * prob_coverage[i] % MOD;
    }

    cout << dp[m] << "\n";
}