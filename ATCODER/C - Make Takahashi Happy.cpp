#include <iostream>
#include <set>
using namespace std;

int H, W;
int A[11][11];

set<int> visited;

int dfs(int x, int y) {
    if (x == H && y == W) {
        return 1;
    }

    int res = 0 , cnt = 0;
    if (x + 1 <= H && visited.find(A[x + 1][y]) == visited.end()) {
        visited.insert(A[x + 1][y]);
        res += dfs(x + 1, y);
        cout << res << endl;
        visited.erase(A[x + 1][y]);
    }
    if (y + 1 <= W && visited.find(A[x][y + 1]) == visited.end()) {
        visited.insert(A[x][y + 1]);
        cnt++;
        //cout << cnt << endl;
        res += dfs(x, y + 1);
        cout << res << endl;
        visited.erase(A[x][y + 1]);
    }

    return res;
}

int main() {
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> A[i][j];
        }
    }

    visited.insert(A[1][1]);
    int ans = dfs(1, 1);
    cout << ans << endl;

    return 0;
}
