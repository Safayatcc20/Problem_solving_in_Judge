#include <iostream>
using namespace std;
typedef long long ll;

ll modpow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ll A, X, M;
    cin >> A >> X >> M;

    ll sum = 0, powA = A % M;
    for (int i = 0; i < 60 && X > 0; i++, X >>= 1) {
        if (X & 1) {
            sum = (sum + modpow(powA, X - 1, M)) % M;
        }
        powA = modpow(powA, 10, M);
    }

    cout << sum << endl;
    return 0;
}
