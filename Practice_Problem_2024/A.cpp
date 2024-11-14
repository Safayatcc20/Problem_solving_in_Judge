#include <iostream>
#include <string>
using namespace std;

int maximizeOnes(string S, int n, int k) {
    int maxOnes = 0;

    // Traverse the string to apply the operation
    for (int i = k; i <= n - k; ++i) {
        // Check if applying the operation at index i will maximize the number of 1's
        int leftOnes = 0, rightZeros = 0;

        // Count 1's in the left part (from S[i] to S[i-k+1])
        for (int j = i; j >= i - k + 1; --j) {
            if (S[j] == '1') leftOnes++;
        }

        // Count 0's in the right part (from S[i+1] to S[i+k])
        for (int j = i + 1; j <= i + k; ++j) {
            if (S[j] == '0') rightZeros++;
        }

        // If the central part has more 0's, apply the operation
        if (leftOnes < k) {
            // Set central part to 1's
            for (int j = i; j >= i - k + 1; --j) {
                S[j] = '1';
            }
            // Set right part to 0's
            for (int j = i + 1; j <= i + k; ++j) {
                S[j] = '0';
            }
        }
    }

    // Calculate total number of 1's in the modified string
    for (char c : S) {
        if (c == '1') maxOnes++;
    }

    return maxOnes;
}

int main() {
	int t ;
	cin >> t;
	while(t--){
	    int n, k;
	    string S;
	
	    // Input length of string, value of k and the binary string S
	    //cout << "Enter the length of the binary string (n): ";
	    cin >> n;
	    //cout << "Enter the value of k: ";
	    cin >> k;
	    //cout << "Enter the binary string S: ";
	    cin >> S;
	
	    // Compute the maximum number of 1's after applying the operation
	    int result = maximizeOnes(S, n, k);
	
	    // Output the result
	    cout << result << endl;
	}
    return 0;
}
