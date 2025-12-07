#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int visited[N];
stack<int> s;
int  cnt;
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
    int t ,  i = 1;
    cin >> t;
    while(t--)
    {
        cout << "Case " << i << ": " ;
        i++;
        int n , m;
        cin >> n >> m;
        vector<vector<int>> g(n + 1), rg(n + 1);
        cnt = 0;
        ans.clear();
        memset(visited, 0, sizeof visited);
        while (m--) {
            int x, y , p = 1;
            cin >> x >> y  ;
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
                dfs2(x , g);
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
