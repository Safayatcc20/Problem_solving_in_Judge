/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define int long long
long long t = 1;
const int INF = LLONG_MAX;

void floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();

    // Applying Floyd-Warshall algorithm
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of graph[i][j]
                if (graph[i][k] != INF && graph[k][j] != INF && graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}
void printShortestDistances( vector<vector<int>>& graph) {
    int V = graph.size();

    //cout << "Shortest path distances between all pairs of vertices:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (graph[i][j] == INF) {
                graph[i][j] = - 1;
                //cout << "INF ";
            } else {
                graph[i][j] -=1;
                //cout << graph[i][j] << " ";
            }
        }
        //cout << endl;
    }
}
vector<vector<int>> pathfloydWarshall(vector<vector<int>>& dist , int l) {
    floydWarshall(dist);
    int V = dist.size();
    vector<vector<int>> fuel(V, vector<int>(V ));
    for(int i = 0 ; i < V; i++){
        for(int j =  0 ; j < V ; j++){
            if(i == j){
                fuel[i][j] = 0;
            }
            else if(dist[i][j] <= l) fuel[i][j] = 1;
            else fuel[i][j] = INF;
        }
    }

    // Applying Floyd-Warshall algorithm
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of graph[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printShortestDistances(fuel);
    return fuel;
}
void solve(){
    int n  , m  , l;
    cin >> n >> m >> l;
    vector<vector<int>> dist(n, vector<int>(n , INF));
    for(int i = 0 ; i < m ; i++){
        int a , b , c;
        cin >> a >>b >> c ;
        a-- , b--;
        dist[a][b] = dist[b][a] = c;
    }
    
    floydWarshall(dist);
    int V = dist.size();
    vector<vector<int>> fuel(V, vector<int>(V , INF ));
    for(int i = 0 ; i < V; i++){
        for(int j =  0 ; j < V ; j++){
            if(i == j){
                fuel[i][j] = 0;
            }
            else if(dist[i][j] <= l) fuel[i][j] = 1;
            else fuel[i][j] = INF;
        }
    }

    // Applying Floyd-Warshall algorithm
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of graph[i][j]
                if (fuel[i][k] != INF && fuel[k][j] != INF && fuel[i][k] + fuel[k][j] < fuel[i][j]) {
                    fuel[i][j] = fuel[i][k] + fuel[k][j];
                }
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int a , b ;
        cin >> a >> b ;
        if(fuel[a-1][b-1] == INF) cout << -1 << sad;
        else cout << fuel[a-1][b-1] - 1<< sad;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}