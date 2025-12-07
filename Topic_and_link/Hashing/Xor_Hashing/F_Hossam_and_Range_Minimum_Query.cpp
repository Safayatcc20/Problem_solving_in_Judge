/***** Bismillahir Rahmanir Rahim *****/
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    ull xorHash = 0;
    int minVal = 0; // smallest number in the segment
};

struct SegmentTree {
    int n;
    vector<Node> tree;
    vector<int> &a;
    unordered_map<int, ull> &hash;

    SegmentTree(vector<int> &arr, unordered_map<int, ull> &h) : a(arr), hash(h) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n-1);
    }

    void build(int node, int l, int r) {
        if(l == r) {
            tree[node].xorHash = hash[a[l]];
            tree[node].minVal = a[l];
            return;
        }
        int m = (l+r)/2;
        build(2*node, l, m);
        build(2*node+1, m+1, r);
        tree[node].xorHash = tree[2*node].xorHash ^ tree[2*node+1].xorHash;
        tree[node].minVal = min(tree[2*node].minVal, tree[2*node+1].minVal);
    }

    // get xor hash for segment [ql, qr]
    ull queryXOR(int node, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return tree[node].xorHash;
        int m = (l+r)/2;
        return queryXOR(2*node, l, m, ql, qr) ^ queryXOR(2*node+1, m+1, r, ql, qr);
    }

    // find smallest number with odd frequency
    int getSmallestOdd(int node, int l, int r, int ql, int qr, ull curXOR) {
        if(qr < l || r < ql) return INT_MAX;
        if(l == r) {
            // leaf
            if(curXOR & hash[a[l]]) return a[l];
            else return INT_MAX;
        }
        int m = (l+r)/2;
        ull leftXOR = queryXOR(2*node, l, m, ql, qr);
        if(leftXOR != 0) return getSmallestOdd(2*node, l, m, ql, qr, leftXOR);
        else return getSmallestOdd(2*node+1, m+1, r, ql, qr, queryXOR(2*node+1, m+1, r, ql, qr));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    unordered_map<int, ull> hash;
    for(auto x : a) hash[x] = rng();

    SegmentTree seg(a, hash);

    int q;
    cin >> q;
    int ans_prev = 0;
    for(int i=0;i<q;i++) {
        int ai, bi;
        cin >> ai >> bi;
        int l = (ai ^ ans_prev) - 1; // 0-based
        int r = (bi ^ ans_prev) - 1;
        if(l > r) swap(l, r);

        ull xor_val = seg.queryXOR(1, 0, n-1, l, r);
        int ans = 0;
        if(xor_val != 0) {
            ans = seg.getSmallestOdd(1, 0, n-1, l, r, xor_val);
        }
        cout << ans << "\n";
        ans_prev = ans;
    }
}
