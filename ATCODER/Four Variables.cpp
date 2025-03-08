#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<int> divisors(n + 1, 0);
    for(long long i = 1; i<= n; i++){
        divisors[i]++;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            divisors[j]++;
        }
    }

    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        long long x = i;
        long long y = n - x;
        ans += (divisors[x]) * (divisors[y]);
    }

    cout << ans << endl;
    return 0;
}
