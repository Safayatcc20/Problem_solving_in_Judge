
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
long long t = 1;
vector<int> bfs(int n, vector<vector<int>>& edges , vector<int>&indegree) {
    priority_queue<int, vector<int>, less<int>> pq;
    queue<int>q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }
    vector<int> order;
    while (!pq.empty()) {
        int node = pq.top();
        pq.pop();
        order.push_back(node);

        for (int neighbor : edges[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                pq.push(neighbor);
            }
        }
    }
    if (order.size() != n) {
        order.clear(); 
    }

    return order;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        long long x , y;
        cin >> x >> y;
        g[x].push_back(y);
        indegree[y]++;
    }
    vector<int> order = bfs(n, g ,indegree);
    if (order.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } 
    else {
        for (int node : order) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
