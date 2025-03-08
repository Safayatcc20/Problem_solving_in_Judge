#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int main() {
    int N;
    cin >> N;

    // precompute primes
    vector<bool> isprime(MAXN, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i < MAXN; i++) {
        if (!isprime[i]) continue;
        for (int j = i * i; j < MAXN; j += i) {
            isprime[j] = false;
        }
    }

    // iterate over all valid triples (a, b, c)
    int cnt = 0;
    for (int a = 2; a * a <= N; a++) {
        if (!isprime[a]) continue;
        for (int b = a + 1; a * a * b  <= N; b+=2) {
            if (!isprime[b]) continue;
            for (int c = b + 2; a * a * b * c * c <= N; c+=2) {
                if (!isprime[c]) continue;
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
