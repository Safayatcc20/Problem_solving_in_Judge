#include <iostream>
#include <vector>

using namespace std;

vector<int> prefixSum(const vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    return prefix;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    string s;
    cin >> s;

    vector<pair<int, int>> substrings(m);
    for (int i = 0; i < m; i++) {
        cin >> substrings[i].first >> substrings[i].second;
    }

    vector<int> updates(q);
    for (int i = 0; i < q; i++) {
        cin >> updates[i];
        updates[i]--;
    }

    vector<int> onesCount(n, 0);
    for (int i = 0; i < m; i++) {
        onesCount[substrings[i].first - 1]++;
        if (substrings[i].second < n) {
            onesCount[substrings[i].second]--;
        }
    }

    vector<int> prefixOnes = prefixSum(onesCount);

    vector<int> totalOnes(n, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            totalOnes[i] = 1;
        }
    }
    vector<int> prefixTotalOnes = prefixSum(totalOnes);

    for (int i = 0; i < q; i++) {
        if (s[updates[i]] == '1') {
            s[updates[i]] = '0';
            prefixTotalOnes[updates[i]]--;
        } else {
            s[updates[i]] = '1';
            prefixTotalOnes[updates[i]]++;
        }

        int maxOnes = 0;
        int currOnes = 0;
        for (int j = 0; j < n; j++) {
            currOnes += prefixOnes[j];
            maxOnes = max(maxOnes, currOnes + prefixTotalOnes[j]);
        }

        int tOnes = maxOnes;
        int tZeros = m - tOnes;

        if (tOnes >= tZeros) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}
