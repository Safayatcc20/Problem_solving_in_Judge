#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Function to apply the special function f(x)
int f(int x) {
    if (x % 2 == 0) return x / 2;
    else return x - 1;
}

// Function to generate the path for a given number with memoization
unordered_set<int> path(int v, unordered_map<int, unordered_set<int>>& memo) {
    if (memo.find(v) != memo.end()) return memo[v];
    
    unordered_set<int> result;
    int original = v;
    while (v != 1) {
        result.insert(v);
        v = f(v);
    }
    result.insert(1); // Add the final 1 to the path
    memo[original] = result;
    return result;
}

int main() {
    long long n, k;
    cin >> n >> k;

    unordered_map<int, int> countMap;
    unordered_map<int, unordered_set<int>> memo;

    // Precompute paths for smaller values with memoization
    for (int i = 1; i <= min(n, 1000000LL); ++i) {
        unordered_set<int> p = path(i, memo);
        for (int val : p) {
            countMap[val]++;
        }
    }

    // Find the maximum value y that appears in at least k different paths
    int maxY = -1;
    for (const auto& entry : countMap) {
        if (entry.second >= k) {
            maxY = max(maxY, entry.first);
        }
    }

    cout << maxY << endl;

    return 0;
}
