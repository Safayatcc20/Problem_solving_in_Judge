#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

struct SegmentTree {
    vector<int> tree;
    int size;

    SegmentTree() {} // Default constructor

    SegmentTree(int n) {
        size = n;
        tree.assign(4 * n, 0);
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        tree[node] = 0;
    }

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            tree[node] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * node, l, mid, pos, val);
        else
            update(2 * node + 1, mid + 1, r, pos, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) +
               query(2 * node + 1, mid + 1, r, ql, qr);
    }
} t;

int main() {
    
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &x: v) cin >> x;


    t = SegmentTree(n);
    
    vector<int> forward(n);
    vector<int> backward(n);
    t.build(1 ,1 , n);
    for(int i = 0 ; i < n ;i++){
        int cnt = t.query(1, 1, n,v[i], n);
        forward[i] = cnt;
        t.update(1, 1 , n,v[i] , 1);
    }
    int total_inv = 0 ;
    for(int i = 0 ;i < n ;i++){
        total_inv += forward[i];
    }
    cout << total_inv << endl;
}
//     t.build(1 ,1 , n);
//     for(int i = n-1; i >= 0;i--){
//         int cnt = t.query(1, 1, n, v[i], n);
//         backward[i] = cnt;
//         t.update(1, 1 , n, v[i] , 1);
//     }
//     int ans = 0 ;
//     for(int i = 0 ;i < n ;i++){
//         ans+= min(backward[i] , forward[i]);
//     }
//     cout << ans <<endl;

//     return 0;
// }
