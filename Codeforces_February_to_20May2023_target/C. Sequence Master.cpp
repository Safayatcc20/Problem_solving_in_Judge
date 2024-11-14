#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(2*n);
        for (int i = 0; i < 2*n; i++) {
            cin >> p[i];
        }
        sort(p.begin(), p.end(), greater<int>());
        vector<int> A(n), B(n);
        int j = 0, k = 0;
        for (int i = 0; i < 2*n; i++) {
            if (i < n) {
                A[j++] = p[i];
            } else {
                B[k++] = p[i];
            }
        }
        long long prodA = 1, prodB = 1, sumA = 0;
        for (int i = 0; i < n; i++) {
            prodA *= A[i];
            prodB *= B[i];
            sumA += A[i];
        }
        if (prodA != prodB + sumA) {
            // no good array exists
            cout << "-1\n";
            continue;
        }
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        long long dist = 0;
        for (int i = 0; i < n; i++) {
            dist += abs(A[i] - B[i]);
        }
        cout << dist << "\n";
    }
    return 0;
}
