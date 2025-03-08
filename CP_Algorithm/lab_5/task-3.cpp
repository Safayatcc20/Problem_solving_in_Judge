#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];

int knapsack(int index, vector<pair<int, int>>& v, int weight) {
    if (index < 0) return 0;
    if (dp[index][weight] != -1) return dp[index][weight];
    if (v[index].first > weight) {
        dp[index][weight] = knapsack(index - 1, v, weight);
        return dp[index][weight];
    }
    return max(v[index].second+knapsack(index-1,v,weight-v[index].first),knapsack(index-1,v,weight));
}
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    memset(dp, -1, sizeof(dp));
    int weight;
    cin >> weight;
    cout << knapsack(n - 1, v, weight) << endl;
}
