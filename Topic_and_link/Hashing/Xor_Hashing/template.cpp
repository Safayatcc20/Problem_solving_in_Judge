/***** Bismillahir Rahmanir Rahim *****/
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using u128 = __uint128_t;
const int MOD = 1e9+7; // optional for mod-hash

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/* ---------------- XOR Hash (for sets/permutations) ---------------- */
struct XorHash {
    vector<ull> h;       // random hash for each number
    vector<ull> pref;    // prefix xor

    XorHash(int n) {
        h.resize(n+1);
        for (int i = 1; i <= n; i++) h[i] = rng();
    }

    void build(const vector<int>& a) {
        int n = a.size();
        pref.assign(n+1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] ^ h[a[i-1]];
        }
    }

    // XOR of subarray [l..r]
    ull get(int l, int r) {
        return pref[r+1] ^ pref[l];
    }
};

/* ---------------- Polynomial Rolling Hash (for strings) ---------------- */
struct RollingHash {
    static const ull base = 911382323; // random odd base
    static const ull mod  = (1ull<<61) - 1; // 61-bit prime (Mersenne)

    vector<ull> pref, power;

    // safe modmul using 128-bit
    ull modmul(ull a, ull b) {
        u128 res = (u128)a * b;
        res = (res >> 61) + (res & mod);
        if (res >= mod) res -= mod;
        return (ull)res;
    }

    RollingHash(const string& s) {
        int n = s.size();
        pref.resize(n+1);
        power.resize(n+1);
        pref[0] = 0;
        power[0] = 1;
        for (int i=0;i<n;i++) {
            pref[i+1] = modmul(pref[i], base) + s[i];
            if (pref[i+1] >= mod) pref[i+1] -= mod;
            power[i+1] = modmul(power[i], base);
        }
    }

    // get hash of substring [l..r]
    ull get(int l, int r) {
        ull res = pref[r+1] + mod - modmul(pref[l], power[r-l+1]);
        if (res >= mod) res -= mod;
        return res;
    }
};

/* ---------------- Example Usage ---------------- */
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* Example 1: XOR Hash for permutations */
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    XorHash H(n);
    H.build(a);

    // check subarray is permutation of 1..len
    int L=0,R=n-1;
    int len = R-L+1;
    vector<ull> good(n+1,0);
    for(int i=1;i<=n;i++) good[i] = good[i-1] ^ H.h[i];

    if(H.get(L,R) == good[len]) cout << "Permutation\n";
    else cout << "Not permutation\n";

    /* Example 2: Rolling Hash for strings */
    string s; cin >> s;
    RollingHash Rh(s);

    // check substring equality
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if(Rh.get(l1,r1) == Rh.get(l2,r2)) cout << "Equal substrings\n";
    else cout << "Different substrings\n";

    return 0;
}
