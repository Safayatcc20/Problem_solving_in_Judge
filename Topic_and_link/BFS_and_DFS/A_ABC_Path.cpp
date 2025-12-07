/***** Bismillahir Rahmanir Rahim *****/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sad '\n'

int h, w;
vector<vector<char>> grid;
vector<vector<int>> dp;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];

    int maxLen = 1;
    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w &&
            grid[nx][ny] == grid[x][y] + 1) {
            maxLen = max(maxLen, 1 + dfs(nx, ny));
        }
    }
    return dp[x][y] = maxLen;
}

void solve() {
    int cs = 1;
    while (cin >> h >> w && h && w) {
        grid.assign(h, vector<char>(w));
        dp.assign(h, vector<int>(w, -1));

        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                cin >> grid[i][j];

        int ans = 0;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                if (grid[i][j] == 'A')
                    ans = max(ans, dfs(i, j));

        cout << "Case " << cs++ << ": " << ans << sad;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
