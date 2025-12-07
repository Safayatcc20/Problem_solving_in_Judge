/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
long long t = 1;
constexpr bool multiple_test_cases = 1;
long long gcd(long long x, long long y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
long long lcm(long long x, long long y)
{
    return ((x * y) / gcd(x, y));
}
const long long N = 1000005;
long long parent[N] , sz[N] ;//create parent array;
void make(long long v){
    parent[v] = v;// indepent node make
    sz[v] = 1;
}
long long find(long long v){
    if(v == parent[v]){
        return v;//parent or root find  of the group;
    }
    // path compression is here
    return parent[v] = find(parent[v]);//change the parent;
}
void Union(long long a , long long b ){//create a set of group 
    a = find(a);//roots of a nodes group; it is left tree(big size tree always);
    b = find(b);// roots of b nodes group; it is right tree(small size tree always);
    if(a != b)//roots are different;
    {
        //union by size
        if(sz[a] < sz[b]){// if a is small size tree then make a is big and b is small;
            swap(a , b);
        }
        parent[b] = a;//parent of b added with parent of a then parent of a , b is parent of a;
        sz[a] += sz[b];//size of a and b are now group;
        //problem solve by size cocept;
    }
}
void solve(){
    // DSU time complexity O(alpha(n));
    // herer alpha(n) is called Reverse ackerman function;it is increase the value so slowly;
    //cp algorithm discuss this code see here link below:
    //https://cp-algorithms.com/data_structures/disjoint_set_union.html#search-for-connected-components-in-an-image'
    /* long long n , k;
    cin >> n >> k;
    for(long long i = 1; i <= n; i++) make(i);
    while(k--){
        int u , v;
        cin >> u >> v;
        Union(u , v);
    }
    int connected_component = 0;// how many roots is the connected component;
    for(long long i =  1; i <= n ; i++){
        if(i == find(i)){
            connected_component++;
        }
    }
    map<int , int>mp;
    for(long long i =  1; i <= n ; i++){
        mp[find(i)]++;// finding the component root and how many nodes are connected there
    }
    cout << connected_component << sad; */
}
int main()
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
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void addEdge(vector<vector<int>>& adjList, int v, int w) {
//     adjList[v].push_back(w);
//     adjList[w].push_back(v);
// }

// void dfs(int v, vector<bool>& visited, vector<int>& component, const vector<vector<int>>& adjList) {
//     visited[v] = true;
//     component.push_back(v);
//     for (int neighbor : adjList[v]) {
//         if (!visited[neighbor]) {
//             dfs(neighbor, visited, component, adjList);
//         }
//     }
// }

// vector<vector<int>> connectedComponents(int size, const vector<vector<int>>& adjList) {
//     vector<bool> visited(size, false);
//     vector<vector<int>> components;
    
//     for (int i = 0; i < size; i++) {
//         if (!visited[i]) {
//             vector<int> component;
//             dfs(i, visited, component, adjList);
//             components.push_back(component);
//         }
//     }
//     return components;
// }

// int minimumCostToReconnectGraphs(int n, vector<pair<int, int>>& edges) {
//     vector<vector<int>> adjList(n);
//     for (const auto& edge : edges) {
//         addEdge(adjList, edge.first, edge.second);
//     }
    
//     vector<vector<int>> components = connectedComponents(n, adjList);
    
//     vector<int> componentSizes;
//     for (const auto& component : components) {
//         componentSizes.push_back(component.size());
//     }
    
//     sort(componentSizes.begin(), componentSizes.end());
    
//     int cost = 0;
//     for (size_t i = 0; i < componentSizes.size() - 1; i++) {
//         cost += componentSizes[i];
//     }
    
//     return cost;
// }

// int main() {
//     vector<pair<int, int>> edges1 = {{1, 2}, {2, 3}, {4, 5}};
//     cout << minimumCostToReconnectGraphs(6, edges1) << endl; // Expected output: 2

//     vector<pair<int, int>> edges2 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
//     cout << minimumCostToReconnectGraphs(5, edges2) << endl; // Expected output: 0

//     return 0;
// }
