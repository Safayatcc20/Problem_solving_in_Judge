#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> marbles(N);

    for (int i = 0; i < N; i++) {
        cin >> marbles[i];
    }

    int Q;
    cin >> Q;

    vector<long long> prefix_sum(N);
    prefix_sum[0] = marbles[0];

    for (int i = 1; i < N; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + marbles[i];
    }

    for (int q = 0; q < Q; q++) {
        int A, B, X;
        cin >> A >> B >> X;

        prefix_sum[A] += X;
        if (B < N - 1) {
            prefix_sum[B + 1] -= X;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << prefix_sum[i] << " ";
    }

    return 0;
}
