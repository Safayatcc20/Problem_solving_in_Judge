#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int powerOfTwo(int exp) {
    int res = 1;
    int base = 2;
    while (exp) {
        if (exp % 2) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int count0 = 0, count1 = 0, count2 = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 0) count0++;
            else if (a[i] == 1) count1++;
            else if (a[i] == 2) count2++;
        }

        int totalSubsequences = powerOfTwo(n) - 1;
        totalSubsequences = (totalSubsequences + MOD) % MOD;

        int pow2_0 = powerOfTwo(count0);
        int pow2_1 = powerOfTwo(count1);
        int pow2_2 = powerOfTwo(count2);

        int mex1_contribution = (pow2_0 - 1 + MOD) % MOD;
        int mex2_contribution = ((pow2_0 - 1) * (pow2_1 - 1)) % MOD;
        int mex3_contribution = ((pow2_0 - 1) * (pow2_1 - 1) * (pow2_2 - 1)) % MOD;

        int result = (mex1_contribution + mex2_contribution + mex3_contribution) % MOD;
        cout << result << endl;
    }

    return 0;
}