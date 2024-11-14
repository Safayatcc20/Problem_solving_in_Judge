#include <bits/stdc++.h>
using namespace std;

#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'

int t = 1;
const long long N = 3 * 1e6;
vector<bool> vis;
vector<long long> a(N), b(N);
stack<long long> s;

void dfs(long long source) {
    vis[source] = true;
    if (b[source] >= 0 && !vis[b[source]]) dfs(b[source]);
    s.push(source);
}

void solve() {
    int n;
    cin >> n;
    //a.resize(N);
    //b.resize(N);
    vis = vector<bool>(N, false);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i);
    }

    vector<int> v, vv;
    long long ans = 0;

    while (!s.empty()) {
        int val = s.top();
        s.pop();
        //if(val >= 0)
        ans += a[val];

        if (val >= 0 and a[val] > 0 && b[val] != -1) {
            a[b[val]] += a[val];
            v.push_back(val + 1);
        } else {
            vv.push_back(val + 1);
        }
    }

    cout << ans << sad;

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    if (!vv.empty()) {
        for (int i = vv.size() - 1; i >= 0; i--) {
            cout << vv[i] << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // Uncomment this line to read the number of test cases.
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}