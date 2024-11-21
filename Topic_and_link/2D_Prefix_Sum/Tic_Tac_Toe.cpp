#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<vector<char>> grid(N + 1, vector<char>(M + 1, 0));
        bool aliceWins = false, bobWins = false;

        for (int turn = 1; turn <= N * M; ++turn) {
            int X, Y;
            cin >> X >> Y;
            char player = (turn % 2 == 1) ? 'A' : 'B';
            grid[X][Y] = player;

            // Check for any KxK subgrid containing (X, Y)
            for (int i = max(1, X - K + 1); i <= X && i + K - 1 <= N; ++i) {
                for (int j = max(1, Y - K + 1); j <= Y && j + K - 1 <= M; ++j) {
                    bool winner = true;
                    for (int a = 0; a < K; ++a) {
                        for (int b = 0; b < K; ++b) {
                            if (grid[i + a][j + b] != player) {
                                winner = false;
                                break;
                            }
                        }
                        if (!winner) break;
                    }
                    if (winner) {
                        if (player == 'A') {
                            cout << "Alice" << '\n';
                        } else {
                            cout << "Bob" << '\n';
                        }
                        return;
                    }
                }
            }
        }

        // If no winner is found
        cout << "Draw" << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
