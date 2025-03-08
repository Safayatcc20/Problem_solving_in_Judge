#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    // Input: Number of coins (n) and the target sum (k)
    int n, k;
    cin >> n >> k;

    // Input: Values of the coins
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    // Step 1: Dynamic Programming to find subsets that sum to k
    // dp1[i][j] = true if a subset of the first i coins can sum to j
    vector<vector<bool>> dp1(n + 1, vector<bool>(k + 1, false));
    dp1[0][0] = true; // Base case: 0 coins sum to 0

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            // If the sum j can be achieved without the current coin
            if (dp1[i - 1][j]) {
                dp1[i][j] = true;
            }
            // If the sum j can be achieved by including the current coin
            if (j >= coins[i - 1] && dp1[i - 1][j - coins[i - 1]]) {
                dp1[i][j] = true;
            }
        }
    }

    // Step 2: Find all possible x for subsets that sum to k
    vector<bool> dp2(k + 1, false);
    dp2[0] = true; // Base case: 0 can always be achieved

    // Iterate through all coins
    for (int i = 0; i < n; ++i) {
        // Update dp2 for all possible sums x
        for (int x = k; x >= coins[i]; --x) {
            if (dp2[x - coins[i]]) {
                dp2[x] = true;
            }
        }
    }

    // Step 3: Collect all sums x that can be achieved using subsets that sum to k
    set<int> possible_x;

    // Iterate over all possible sums x
    for (int x = 0; x <= k; ++x) {
        if (dp2[x]) {
            possible_x.insert(x);
        }
    }

    // Step 4: Output the results
    // Number of unique sums x
    cout << possible_x.size() << endl;

    // Print all unique sums x in ascending order
    for (int x : possible_x) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}