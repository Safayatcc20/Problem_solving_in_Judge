#include <bits/stdc++.h>
using namespace std;

void build(vector<long long>& v, vector<long long>& create, long long node, long long start, long long end) {
    if (start == end) {
        create[node] = v[start];
        return;
    }

    long long mid = (start + end) / 2;
    build(v, create, 2 * node + 1, start, mid);
    build(v, create, 2 * node + 2, mid + 1, end);
    create[node] = create[2 * node + 1] & create[2 * node + 2];
}

long long query(vector<long long>& create, long long node, long long ft, long long lt, long long l, long long r) {
    if (lt < l || r < ft) {
        return -1;
    }
    if (l <= ft && lt <= r) {
        return create[node];
    }

    long long mid = (ft + lt) / 2;
    long long left = query(create, 2 * node + 1, ft, mid, l, r);
    long long right = query(create, 2 * node + 2, mid + 1, lt, l, r);

    if (left == -1) {
        return right;
    }
    if (right == -1) {
        return left;
    }
    return left & right;
}

void solve() {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (auto& x : v) cin >> x;
    long long q;
    cin >> q;
    vector<long long> create(4 * n); // Reduce the size to 4 * n

    build(v, create, 0, 0, n - 1);

    while (q--) {
        long long l, k;
        cin >> l >> k;
        l--;
        long long r = n - 1, ll = l;
        long long ans = -1;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (query(create, 0, 0, n - 1, ll, mid) >= k) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        if (ans == -1) cout << ans << " ";
        else cout << ans + 1 << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
