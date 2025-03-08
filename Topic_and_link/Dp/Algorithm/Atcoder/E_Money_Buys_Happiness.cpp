#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
    int N;
    long long W;
    cin >> N >> W;

    vector<long long> weights(N);
    vector<int> values(N);
    int totalValue = 0;

    for (int i = 0; i < N; ++i) {
        cin >> weights[i] >> values[i];
        totalValue += values[i];
    }

    // DP array to store the minimum weight needed to achieve each possible value
    vector<long long> dp(totalValue + 1, LLONG_MAX);
    dp[0] = 0;  // Base case: 0 weight needed to achieve 0 value

    for (int i = 0; i < N; ++i) {
        for (int v = totalValue; v >= values[i]; --v) {
            if (dp[v - values[i]]*W != LLONG_MAX) {
                dp[v] = min(dp[v], dp[v - values[i]] + weights[i]);
            }
        }
    }

    // Find the maximum value that can be achieved within the weight limit W
    int maxAchievableValue = 0;
    for (int v = 0; v <= totalValue; ++v) {
        if (dp[v] <= W) {
            maxAchievableValue = v;
        }
    }

    cout << maxAchievableValue << endl;
    }

    return 0;
}
