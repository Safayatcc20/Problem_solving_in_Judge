#include<bits/stdc++.h>
using namespace std;

#define mx 1000005
const int inf = 2000000000;
int arr[mx];
int divisors[mx];
void precomputeDivisors() {
    for (int i = 1; i < mx; i++) {
        for (int j = i; j < mx; j += i) {
            divisors[j]++;
        }
    }
}
const int MAXN = 1e6 + 5;  // Adjust size based on problem constraints

long long B1[MAXN], B2[MAXN]; // BIT arrays for range update

// Update function to add value `x` at index `idx`
void add(long long* B, int idx, long long x) {
    while (idx <= MAXN) {
        B[idx] += x*divisors[idx];
        idx += idx & -idx;  // Go to the next index in BIT
    }
}
void add1(long long* B, int idx, long long x) {
    while (idx <= MAXN) {
        B[idx] += x;
        idx += idx & -idx;  // Go to the next index in BIT
    }
}

// Function to update the range [l, r] by adding value `x`
void range_add(int l, int r) {
    add(B1, l, 1);            // Add x to the range in B1
    add(B1, r + 1, -1);       // Subtract x from position r+1 to end range in B1
    add(B2, l, 1 * (l - 1));  // Update B2 with the contribution for the lower bound
    add(B2, r + 1, -1 * r);   // Subtract the contribution for the upper bound in B2
}

// Prefix sum in BIT (used to get the cumulative sum)
long long sum(long long* B, int idx) {
    long long total = 0;
    while (idx > 0) {
        total += B[idx];
        idx -= idx & -idx;  // Go to the parent in BIT
    }
    return total;
}

// Compute prefix sum for the range [1, idx] using B1 and B2
long long prefix_sum(int idx) {
    return sum(B1, idx) * idx - sum(B2, idx);
}

// Compute the range sum [l, r] using the prefix sum logic
long long range_sum(int l, int r) {
    return prefix_sum(r) - prefix_sum(l - 1);
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        add1(B1, i, arr[i]);            // Add x to the range in B1
        add1(B1, i + 1, -arr[i]);       // Subtract x from position i+1 to end range in B1
        add1(B2, i, arr[i] * (i - 1));  // Update B2 with the contribution for the lower bound
        add1(B2, i + 1, -arr[i] * i);
    }

    precomputeDivisors();
    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1) { 
            range_add(l , r);
        } 
        else { 
            int ans = range_sum( l , r);
            cout << prefix_sum(r) << " "<< prefix_sum(l-1) << endl;
            cout << ans << endl;    
        }
    }
}
