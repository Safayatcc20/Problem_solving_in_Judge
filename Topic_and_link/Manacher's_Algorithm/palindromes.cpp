#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> f;
    BIT(int _n): n(_n), f(n+1, 0) {}
    void update(int i, int v = 1) {
        for (; i <= n; i += i & -i)
            f[i] += v;
    }
    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += f[i];
        return s;
    }
    int query(int l, int r) {
        if (r < l) return 0;
        return query(r) - query(l - 1);
    }
};

vector<pair<int,int>> getPalindromes(const string &s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }
    int n = t.size();
    vector<int> P(n);
    int center = 0, right = 0;
    vector<pair<int,int>> pal;

    for (int i = 0; i < n; i++) {
        if (i < right)
            P[i] = min(right - i, P[2*center - i]);
        while (i - P[i] - 1 >= 0 && i + P[i] + 1 < n
               && t[i - P[i] - 1] == t[i + P[i] + 1])
            P[i]++;
        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }
        // Record all palindromes centered at i
        for (int rad = 1; rad <= P[i]; rad++) {
            int l = (i - rad) / 2 + 1;
            int r = (i + rad) / 2;
            pal.emplace_back(l, r);
        }
    }
    return pal;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int Q;
    cin >> s >> Q;
    int n = s.size();

    vector<pair<int,int>> pal = getPalindromes(s);
    // Organize palindromes by their right end
    vector<vector<int>> at(n + 2);
    for (auto &p : pal) {
        int l = p.first, r = p.second;
        at[r].push_back(l);
    }

    struct Query { int l, r, idx; };
    vector<Query> queries(Q);
    for (int i = 0; i < Q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }
    sort(queries.begin(), queries.end(), [](auto &a, auto &b){
        return a.r < b.r;
    });

    BIT bit(n);
    vector<int> ans(Q);
    int qi = 0;

    for (int r = 1; r <= n; r++) {
        for (int l : at[r]) {
            bit.update(l, 1);
        }
        while (qi < Q && queries[qi].r == r) {
            ans[queries[qi].idx] = bit.query(queries[qi].l, queries[qi].r);
            qi++;
        }
    }

    for (int v : ans) cout << v << "\n";
    return 0;
}
