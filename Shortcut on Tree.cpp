#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 2; i <= n; i++) {
            cin >> p[i];
        }
        
        // Output edges i -> 1 for all i != 1
        cout << "Yes\n";
        cout << n - 1 << "\n";
        for (int i = 2; i <= n; i++) {
            cout << i << " " << 1 << "\n";
        }
    }
    
    return 0;
}