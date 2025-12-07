#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int visited[N];
stack<int> s;
int n, m, cnt;
vector<vector<int>> ans;

void dfs1(int x , vector<vector<int>>&g) {
    visited[x] = true;
    for (int i = 0; i < g[x].size(); i++) {
        int to = g[x][i];
        if (!visited[to]) dfs1(to , g);
    }
    s.push(x);
}

void dfs2(int x , vector<vector<int>>&rg) {
    visited[x] = true;
    ans[cnt].push_back(x);
    for (int i = 0; i < rg[x].size(); i++) {
        int to = rg[x][i];
        if (!visited[to]) dfs2(to , rg);
    }
}

int main() {
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0){
            return 0;
        }
        vector<vector<int>> g(n + 1), rg(n + 1);
        cnt = 0;
        ans.clear();
        memset(visited, 0, sizeof visited);
        while (m--) {
            int x, y , p;
            cin >> x >> y >> p;
            if(p == 1)
            {
                g[x].push_back(y);
                rg[y].push_back(x);
            }
            else{
                g[x].push_back(y);
                g[y].push_back(x);
                rg[y].push_back(x);
                rg[x].push_back(y);
            }
        }
        for (int i = 1; i <= n; i++)
            if (!visited[i]) dfs1(i , g);
        memset(visited, 0, sizeof visited);
        while (s.size()) {
            int x = s.top();
            s.pop();
            if (!visited[x]) {
                ans.push_back(vector<int>());
                dfs2(x , rg);
                cnt++;
            }
        }
        if(cnt == 1){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}
