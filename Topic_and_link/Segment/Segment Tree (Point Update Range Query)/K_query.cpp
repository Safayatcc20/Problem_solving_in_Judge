#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 30000;
const int MAX_Q = 200000;

int n, q;
vector<int> a(MAX_N + 1);  // Array to store elements
vector<ordered_set> seg_tree(4 * MAX_N);  // Segment Tree of ordered sets

// Build the segment tree
void build(int node, int start, int end) {
    if (start == end) {
        seg_tree[node].insert(a[start]);  // Insert the element into the segment tree
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        seg_tree[node].insert(a[start]);  // Insert the element into the segment tree
    }
}

// Query the segment tree for range (l, r)
int query(int node, int start, int end, int l, int r, int k) {
    // If the query range is outside the segment range, return 0
    if (r < start || end < l) {
        return 0;
    }
    
    // If the query range completely covers the segment range
    if (l <= start && end <= r) {
        return seg_tree[node].size() - seg_tree[node].order_of_key(k + 1); // Count elements greater than k
    }

    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r, k) + query(2 * node + 1, mid + 1, end, l, r, k);
}

// Update the segment tree
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        seg_tree[node].erase(a[start]);
        a[start] = val;
        seg_tree[node].insert(a[start]);
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        seg_tree[node].erase(a[start]);
        a[start] = val;
        seg_tree[node].insert(a[start]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // Read input
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Build segment tree
    build(1, 1, n);

    // Number of queries
    cin >> q;

    // Process each query
    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;
        
        // For the query, get the count of numbers greater than k in range (i, j)
        cout << query(1, 1, n, i, j, k) << "\n";
    }

    return 0;
}
