#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 3e5 + 5;

vector<int> a(MAXN);
unordered_map<int, int> compress, decompress;
int n, q;

struct SegmentTree {
    vector<unordered_map<int, int>> tree;
    SegmentTree(int size) {
        tree.resize(4 * size);
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node][a[start]] = 1;
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            merge(node);
        }
    }

    void merge(int node) {
        tree[node].clear();
        for (auto& x : tree[2 * node]) {
            tree[node][x.first] += x.second;
        }
        for (auto& x : tree[2 * node + 1]) {
            tree[node][x.first] += x.second;
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node].clear();
            tree[node][val] = 1;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            merge(node);
        }
    }

    unordered_map<int, int> query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return {};
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        auto left = query(2 * node, start, mid, l, r);
        auto right = query(2 * node + 1, mid + 1, end, l, r);
        for (auto& x : right) {
            left[x.first] += x.second;
        }
        return left;
    }
};

void solve() {
    cin >> n >> q;
    vector<int> unique_vals;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        unique_vals.push_back(a[i]);
    }
    sort(unique_vals.begin(), unique_vals.end());
    unique_vals.erase(unique(unique_vals.begin(), unique_vals.end()), unique_vals.end());
    for (int i = 0; i < unique_vals.size(); i++) {
        compress[unique_vals[i]] = i;
        decompress[i] = unique_vals[i];
    }
    for (int i = 0; i < n; i++) {
        a[i] = compress[a[i]];
    }

    SegmentTree segTree(n);
    segTree.build(1, 0, n - 1);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            x = compress[x];
            segTree.update(1, 0, n - 1, i, x);
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            l--; r--;
            auto freq_map = segTree.query(1, 0, n - 1, l, r);
            bool valid = true;
            for (auto& x : freq_map) {
                if (x.second % k != 0) {
                    valid = false;
                    break;
                }
            }
            cout << (valid ? "YES" : "NO") << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
