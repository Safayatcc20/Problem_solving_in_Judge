#include <bits/stdc++.h>
using namespace std;
#define long long int
const int MAXN = 200005;  // Maximum number of elements

struct SegmentTreeNode {
    int max_val, second_max_val;
    int max_count, second_max_count;
};

SegmentTreeNode segTree[4 * MAXN];
int A[MAXN];

// Merge two segment tree nodes
SegmentTreeNode merge(SegmentTreeNode left, SegmentTreeNode right) {
    SegmentTreeNode result;
    if (left.max_val > right.max_val) {
        result.max_val = left.max_val;
        result.max_count = left.max_count;
        result.second_max_val = max(left.second_max_val, right.max_val);
        result.second_max_count = (left.second_max_val == result.second_max_val) ? left.second_max_count : right.max_count;
    } else if (left.max_val < right.max_val) {
        result.max_val = right.max_val;
        result.max_count = right.max_count;
        result.second_max_val = max(left.max_val, right.second_max_val);
        result.second_max_count = (right.second_max_val == result.second_max_val) ? right.second_max_count : left.max_count;
    } else {
        result.max_val = left.max_val;
        result.max_count = left.max_count + right.max_count;
        result.second_max_val = max(left.second_max_val, right.second_max_val);
        result.second_max_count = (left.second_max_val == result.second_max_val) ? left.second_max_count : right.second_max_count;
    }
    return result;
}

// Build the segment tree
void build(int node, int start, int end) {
    if (start == end) {
        segTree[node].max_val = A[start];
        segTree[node].max_count = 1;
        segTree[node].second_max_val = 0;
        segTree[node].second_max_count = 0;
        return;
    }
    int mid = (start + end) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    build(left, start, mid);
    build(right, mid + 1, end);
    segTree[node] = merge(segTree[left], segTree[right]);
}

// Update the value at index idx
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        A[start] = val;
        segTree[node].max_val = val;
        segTree[node].max_count = 1;
        segTree[node].second_max_val = 0;
        segTree[node].second_max_count = 0;
        return;
    }
    int mid = (start + end) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    if (start <= idx && idx <= mid) {
        update(left, start, mid, idx, val);
    } else {
        update(right, mid + 1, end, idx, val);
    }
    segTree[node] = merge(segTree[left], segTree[right]);
}

// Query the range [l, r] for the second largest value and its count
SegmentTreeNode query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return {INT_MIN, INT_MIN, 0, 0};  // No overlap
    }
    if (l <= start && end <= r) {
        return segTree[node];  // Total overlap
    }
    int mid = (start + end) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    SegmentTreeNode leftResult = query(left, start, mid, l, r);
    SegmentTreeNode rightResult = query(right, mid + 1, end, l, r);
    return merge(leftResult, rightResult);  // Partial overlap
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    build(1, 1, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int p, x;
            cin >> p >> x;
            update(1, 1, n, p, x);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            SegmentTreeNode result = query(1, 1, n, l, r);
            if (result.second_max_val == INT_MIN) {
                cout << "0\n";  // No second largest value
            } else {
                cout << result.second_max_count << "\n";
            }
        }
    }

    return 0;
}
