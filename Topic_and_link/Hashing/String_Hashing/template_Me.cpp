#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

// -------------------- Precomputation --------------------
const int N = 1e6 + 5;     // maximum string/array length
const int MOD1 = 1e9 + 7;  
const int MOD2 = 1e9 + 9;  
const int P1 = 31;         // base 1
const int P2 = 53;         // base 2

int pw1[N], pw2[N];         // powers
int ipw1[N], ipw2[N];       // inverse powers

int power(int n, int k, int mod) {
    int res = 1;
    n %= mod;
    while (k) {
        if (k & 1) res = 1LL * res * n % mod;
        n = 1LL * n * n % mod;
        k >>= 1;
    }
    return res;
}

void precalc(int maxN) {
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i <= maxN; i++) {
        pw1[i] = 1LL * pw1[i-1] * P1 % MOD1;
        pw2[i] = 1LL * pw2[i-1] * P2 % MOD2;
    }
    int inv1 = power(P1, MOD1-2, MOD1);
    int inv2 = power(P2, MOD2-2, MOD2);
    ipw1[0] = ipw2[0] = 1;
    for (int i = 1; i <= maxN; i++) {
        ipw1[i] = 1LL * ipw1[i-1] * inv1 % MOD1;
        ipw2[i] = 1LL * ipw2[i-1] * inv2 % MOD2;
    }
}

// -------------------- Hashing Class --------------------
struct Hashing {
    int n;
    vector<int> arr;           // can be string (ASCII) or integer array
    vector<pair<int,int>> hs;  // prefix hashes (1-indexed)

    Hashing() {}
    Hashing(const vector<int>& _arr) {
        n = _arr.size();
        arr = _arr;
        hs.emplace_back(0,0);
        for (int i = 0; i < n; i++) {
            int h1 = (hs[i].first + 1LL * pw1[i] * arr[i]) % MOD1;
            int h2 = (hs[i].second + 1LL * pw2[i] * arr[i]) % MOD2;
            hs.emplace_back(h1, h2);
        }
    }

    // Get hash of subarray [l,r] (0-indexed)
    pair<int,int> get_hash(int l, int r) {
        int h1 = (hs[r+1].first - hs[l].first + MOD1) % MOD1;
        h1 = 1LL * h1 * ipw1[l] % MOD1;
        int h2 = (hs[r+1].second - hs[l].second + MOD2) % MOD2;
        h2 = 1LL * h2 * ipw2[l] % MOD2;
        return {h1, h2};
    }

    // Full array hash
    pair<int,int> get_hash() {
        return get_hash(0, n-1);
    }
};

// -------------------- Example Usage --------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precalc(N-1);  // precompute powers & inverse powers

    string s = "ABAB";
    string p = "AB";

    // convert string to integer array (a=1, b=2, etc.)
    vector<int> S(s.size()), P(p.size());
    for (int i = 0; i < s.size(); i++) S[i] = s[i]-'A'+1;
    for (int i = 0; i < p.size(); i++) P[i] = p[i]-'A'+1;

    Hashing H(S);
    pair<int,int> hashP = Hashing(P).get_hash();

    int n = S.size(), m = P.size();
    for (int i = 0; i + m <= n; i++) {
        if (H.get_hash(i, i+m-1) == hashP) cout << i << "\n";  // 0-based index
    }
}
