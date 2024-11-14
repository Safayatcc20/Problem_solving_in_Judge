#include <iostream>
#include <vector>
#include <unordered_map>

#define MOD 1000000007
using namespace std;

long long calculatePartitionSum(const vector<long long>& arr) {
    int n = arr.size();
    vector<long long> prefixXor(n + 1, 0);
    
    // Step 1: Build the prefix XOR array
    for (int i = 1; i <= n; i++) {
        prefixXor[i] = prefixXor[i - 1] ^ arr[i - 1];
    }

    // Step 2: Create a DP array to hold partition sums
    vector<long long> dp(n + 1, 0);
    dp[0] = 1; // Base case: empty partition contributes 1
    
    // Step 3: Calculate the contribution of all partitions
    int cnt  = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = cnt; j < i; j++) {
            long long segmentXor = prefixXor[i] ^ prefixXor[j];
            dp[i] = (dp[i] + dp[j] * segmentXor) % MOD;
        }
    }

    // Step 4: The result will be in dp[n], excluding the empty partition
    return dp[n];
}

int main() {
    int n;
    cin >> n;  // Input length of the array
    vector<long long> arr(n);

    // Input array elements
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Call the function to calculate the sum of all partition products
    long long result = calculatePartitionSum(arr);

    // Output the result modulo 10^9 + 7
    cout << result << endl;

    return 0;
}
