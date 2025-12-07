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

const int INF = INT_MAX;

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
int printShortestDistances(const vector<vector<int>>& dist) {
    int n = dist.size();

    int sum = 0 ;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (dist[i][j] == INF) {
                    //cout << "INF ";
                    continue;
                } 
                else {
                    //cout << dist[i][j] << " ";
                    sum+=dist[i][j];
                }
            }
            //cout << "\n";
        }
        //cout << sum << " ";
        return sum;
}
void solve(){
    int n ;
    cin >> n;
    int v[n][n];
    vector<vector<int>> dist(n, vector<int>(n));
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            cin >> dist[i][j];
        }
    }
    floydWarshall(dist);
    int k ;
    cin >> k;
    while(k--){
        int a , b , c ;
        cin >> a >> b >> c;
        a-- , b--;
        /* The current distance dist[i][j] remains unchanged.
        The new road from a to b provides a shorter path. In this case,
        the code calculates the distance if the path from i to a, then 
        from a to b, and finally from b to j is shorter than the current shortest 
        distance. It compares dist[i][j] with dist[i][a] + c + dist[b][j].
        Similarly, it also considers the possibility of using the road 
        from b to a. So, it compares dist[j][i] with dist[j][a] + c + dist[b][i] */
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j] , dist[i][a] + c + dist[b][j]);
                    dist[j][i] = min(dist[j][i] , dist[i][a] + c + dist[b][j]);
            }
        }
        /* int sum = 0 ;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (dist[i][j] == INF) {
                    //cout << "INF ";
                    continue;
                } 
                else {
                    //cout << dist[i][j] << " ";
                    sum+=dist[i][j];
                }
            }
            //cout << "\n";
        }
        cout << sum << " "; */
        cout << printShortestDistances(dist) << " ";
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