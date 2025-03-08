#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Create adjacency list to represent the graph
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    // Check each connected component for the condition
    bool all_components_satisfy = true;
    unordered_set<int> visited;
    for (int i = 0; i < n; i++) {
        if (visited.count(i) == 0) {
            int num_vertices = 0, num_edges = 0;
            bool component_satisfies = true;
            vector<int> to_visit = {i};
            while (!to_visit.empty()) {
                int u = to_visit.back();
                to_visit.pop_back();
                if (visited.count(u) == 0) {
                    visited.insert(u);
                    num_vertices++;
                    num_edges += adj[u].size();
                    for (int v : adj[u]) {
                        to_visit.push_back(v);
                    }
                }
            }
            num_edges /= 2;  // each edge is counted twice in the adjacency list
            if (num_vertices != num_edges) {
                component_satisfies = false;
            }
            all_components_satisfy = all_components_satisfy && component_satisfies;
        }
    }

    // Output the result
    if (all_components_satisfy) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
