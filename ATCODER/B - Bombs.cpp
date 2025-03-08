#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;

int R, C;
char B[MAXN][MAXN];
bool destroyed[MAXN][MAXN];

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (B[i][j] >= '1' && B[i][j] <= '9') {
                int power = B[i][j] - '0';
                destroyed[i][j] = true;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dr[k], nj = j + dc[k];
                    for (int p = 1; p <= power; p++) {
                        if (ni < 0 || ni >= R || nj < 0 || nj >= C || B[ni][nj] == '#') {
                            break;
                        }
                        destroyed[ni][nj] = true;
                        ni += dr[k], nj += dc[k];
                    }
                }
            }
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << (destroyed[i][j] ? '.' : B[i][j]);
        }
        cout << endl;
    }
    return 0;
}
