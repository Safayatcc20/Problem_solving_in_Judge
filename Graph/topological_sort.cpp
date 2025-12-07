#include<bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
stack<long>s;
vector<long long>vis(N);
/* // Function to return list containing vertices in
// Topological order.
vector<int> topologicalSort(vector<vector<int> >& adj,
                            int V)
{
    // Vector to store indegree of each vertex
    vector<int> indegree(V);
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }
 
    // Queue to store vertices with indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
       
        // Decrease indegree of adjacent vertices as the
        // current node is in topological order
        for (auto it : adj[node]) {
            indegree[it]--;
           
            // If indegree becomes 0, push it to the queue
            if (indegree[it] == 0)
                q.push(it);
        }
    }
 
    // Check for cycle
    if (result.size() != V) {
        cout << "Graph contains cycle!" << endl;
        return {};
    }
 
    return result;
} 
int main()
{
 
    // Number of nodes
    int n = 4;
 
    // Edges
    vector<vector<int> > edges
        = { { 0, 1 }, { 1, 2 }, { 3, 1 }, { 3, 2 } };
 
    // Graph represented as an adjacency list
    vector<vector<int> > adj(n);
 
    // Constructing adjacency list
    for (auto i : edges) {
        adj[i[0]].push_back(i[1]);
    }
 
    // Performing topological sort
    cout << "Topological sorting of the graph: ";
    vector<int> result = topologicalSort(adj, n);
 
    // Displaying result
    for (auto i : result) {
        cout << i << " ";
    }
 
    return 0;
}*/
void dfs(long long source , vector<vector<long long>>&g){
    vis[source] = 1;
    for(long long i = 0 ; i < g[source].size() ; i++){
        if(vis[g[source][i]] != 1){
            vis[g[source][i]] = 1;
            dfs(g[source][i] , g);
        }
    }
    s.push(source);
}
int main(){
    long long  n , m;
    cin >> n >> m;
    vector<vector<long long>>g(n+1) , rg(n+1);
    for(long long i = 0 ; i < n ; i++){
        long long u , v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for(long long i = 1; i <= n; i++){
        if(vis[i] != 1){
            dfs(i , g);
        }
    }
    while(s.size()){
        cout << s.top() << " ";
        s.pop();
    }
}