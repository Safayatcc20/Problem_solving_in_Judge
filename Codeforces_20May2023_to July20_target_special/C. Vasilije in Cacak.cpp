#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

// Function to perform a single modification on the string
string modifyString(string s, vector<int>& l, vector<int>& r, int x) {
    int i = 0;
    while (i < l.size() && x > r[i]) {
        i++;
    }
    int a = min(x, r[i] + l[i] - x);
    int b = max(x, r[i] + l[i] - x);
    reverse(s.begin() + a - 1, s.begin() + b);
    return s;
}

// Function to process a test case
string processTestCase(int n, int k, string s, vector<int>& l, vector<int>& r, int q, vector<int>& modifications) {
    for (int i = 0; i < q; i++) {
        s = modifyString(s, l, r, modifications[i]);
    }
    return s;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> l(k), r(k);
        for (int i = 0; i < k; i++) {
            cin >> l[i];
        }
        for (int i = 0; i < k; i++) {
            cin >> r[i];
        }
        int q;
        cin >> q;
        vector<int> modifications(q);
        for (int i = 0; i < q; i++) {
            cin >> modifications[i];
        }
        string result = processTestCase(n, k, s, l, r, q, modifications);
        cout << result << endl;
    }
    return 0;
}
