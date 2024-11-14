/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
long long t = 1;
int n , m;
bool vis[1010][1010];
vector<vector<int>>v(1010, vector<int>(1010));
int dfs( int i , int j){
    vis[i][j] = true;
    int sum = v[i][j];
    if(i-1 >= 0 and !vis[i-1][j] and v[i-1][j]!= 0) sum +=dfs( i-1 , j);
    if(i+1 < n and !vis[i+1][j] and v[i+1][j]!= 0) sum +=dfs( i+1 , j);
    if(j-1 >= 0 and !vis[i][j-1] and v[i][j-1]!= 0) sum +=dfs( i , j-1);
    if(j +1 < m and !vis[i][j+1] and v[i][j+1]!= 0) sum +=dfs( i , j+1);
    return sum;
}
void solve(){
    cin >> n >> m;
    for(int i = 0 ; i < n  ; i++){
        for(int j  = 0 ; j < m ; j++){
            vis[i][j] = false;
            cin >> v[i][j];
        }
    }
    int ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ;j < m ;j++){
            if(!vis[i][j] and v[i][j] != 0)
            ans = max(ans , dfs(i  , j));
        }
    }
    cout << ans << sad;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}