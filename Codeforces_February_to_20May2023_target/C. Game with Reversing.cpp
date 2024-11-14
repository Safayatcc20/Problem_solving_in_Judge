#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string S, T;
        cin >> S >> T;

        int duration = 0;

        if (S == T) {
            cout << 0 << endl;
            continue;
        }

        int diffCount = 0;
        for (int i = 0; i < n; i++) {
            if (S[i] != T[i]) {
                diffCount++;
            }
        }

        if (diffCount == 1) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }

    return 0;
}
