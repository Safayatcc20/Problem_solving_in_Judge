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
const long long N = 1e5+10;
void dfs(int node , unordered_map<int , bool>&vis , stack<int>&st , unordered_map<int,list<int>>&adj){
    vis[node] = true;
    for(auto &nbr:adj[node]){
        if(!vis[nbr]){
            dfs(nbr , vis , st , adj);
        }
    }
    st.push(node);
}
void revDfs(int node , unordered_map<int , bool>&vis , unordered_map<int,list<int>>&adj){
    vis[node] = true;
    for(auto &nbr:adj[node]){
        if(!vis[nbr]){
            revDfs(nbr , vis  , adj);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    //  `cin >> t;
    while (t--)
    {
        int n  , m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        for(int i = 0 ; i < m; i++){
            int u , v , w;
            cin >> u >> v ;
            g[u].push_back(v);
        }

        //adjacent
        unordered_map<int , list<int>>adj;
        for(int i = 0 ; i <g.size(); i++){
            int u = g[i][0];
            int v = g[i][1];
            adj[u].push_back(v);
        }

        //topological sort;
        stack<int>st;
        unordered_map<int , bool>vis;
        for(int i = 0; i < n;i++){
            if(!vis[i]){
                dfs(i , vis , st , adj);
            }
        }

        //create a transpose graph
        unordered_map<int , list<int>>transpose;
        for(int i = 0 ; i < n; i++){
            vis[i] = 0;
            for(auto &nbr:adj[i]){
                transpose[nbr].push_back(i);
            }
        }
        //dfs call using above ordering
        int cnt = 0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if(!vis[top]){
                cnt++;
                revDfs(top , vis , transpose);
            }
        }
        cout << cnt << sad;
        //complexity o(node + edges);
    }
}