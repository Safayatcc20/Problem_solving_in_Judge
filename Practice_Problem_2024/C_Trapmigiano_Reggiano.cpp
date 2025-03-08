/***** Bismillahir Rahmanir Rahim *****/

#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key(x) returns number of elements strictly less than x
// find_by_order(x) return x-th element of the set (0-based index)

#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
#define int long long

long long t = 1;
constexpr bool multiple_test_cases = 1;

long long gcd(long long x, long long y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

long long lcm(long long x, long long y) {
    return ((x * y) / gcd(x, y));
}

long long fact(long long n) {
    if (n == 0) return 1;
    return n * fact(n - 1);
}

long long findXor(long long n) { 
    long long rest = n % 4;
    if (rest == 0) return n;
    if (rest == 1) return 1;
    if (rest == 2) return n + 1;
    if (rest == 3) return 0;
    return 0;
}

// Linear Diophantine Equation ax + by = c
// If c % gcd(a, b) == 0 then solution exists, otherwise not
int extgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// Euler totient function for single call
int phi(int n) {
    int ans = n;
    for (int i = 2; i * i <= n; i++) { 
        if (n % i == 0) {
            ans /= i;
            ans *= (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ans /= n, ans *= (n - 1);
    return ans;
}

// Euler totient preprocessing (from 1 to n) in O(n log log(n))
vector<int> phai(1e7 + 10);
void init() {
    int maxn = 1e7 + 10;
    for (int i = 1; i <= maxn; i++) {
        phai[i] = i;
    }
    for (int i = 2; i <= maxn; i++) {
        if (phai[i] == i) {
            for (int j = i; j <= maxn; j += i) {
                phai[j] /= i;
                phai[j] *= (i - 1);
            }
        }
    }
}

void dfs(int u, vector<vector<int>>& g, int par, vector<int>& deg) {
    for (int &v : g[u]) {
        if (v != par) {  
            deg[v] = deg[u] + 1;
            dfs(v, g, u, deg);
        }
    }
}

bool comp(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
}

void solve() {
    int n, st, en;
    cin >> n >> st >> en;
    
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> ans(n);  
    for (int i = 0; i < n; i++) {
        ans[i] = i + 1;
    }

    vector<int> deg(n + 1, -1);
    deg[en] = 0;
    dfs(en, g, -1, deg);
    if (deg[st] == -1) {
        cout << -1 << sad;
    } else {
        vector<pair<int, int>> p(n);
        for (int i = 1; i <= n; i++) {
            p[i - 1] = {i, deg[i]};
        }
        sort(all(p), comp);
        for (int i = 0; i < n; i++) {
            cout << p[i].first << " ";
        }
        cout << sad;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.tie(0);
    
    cin >> t;
    while (t--) {
        solve();
    }
}
