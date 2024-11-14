#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    ll ans = 0;
    for(int i=0; i<n; i++) {
        ans ^= (a[i] ^ b[i]); // calculate the XOR of each corresponding element
    }

    cout << ans << endl;

    return 0;
}
