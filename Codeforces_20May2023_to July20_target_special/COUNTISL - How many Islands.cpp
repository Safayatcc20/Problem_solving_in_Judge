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
vector<string>v(100);
bool vis[100][100];
int ans = 1;
int col , row;
void dfs(int i , int j){
    vis[i][j] = true;
    if(i+1 < row and !vis[i+1][j] and v[i+1][j] == '#') {
        ans++;
        dfs(i+1 , j);
    }
    if(i-1 >= 0 and !vis[i-1][j] and v[i-1][j] == '#') {
        ans++;
        dfs(i-1 , j);
    }
    if(j+1 < col and !vis[i][j+1] and v[i][j+1] == '#') {
        ans++;
        dfs(i , j+1);
    }
    if(j-1 >= 0 and !vis[i][j-1] and v[i][j-1] == '#') {
        ans++;
        dfs(i , j-1);
    }
    if(i+1 < row and j - 1 >= 0 and !vis[i+1][j-1] and v[i+1][j-1] == '#') {
        ans++;
        dfs(i+1 , j-1);
    }
    if(i-1 >= 0 and j + 1 < col and !vis[i-1][j+1] and v[i-1][j+1] == '#') {
        ans++;
        dfs(i-1 , j);
    }
    if(i+1 < row and j+1 < col and !vis[i+1][j+1] and v[i+1][j+1] == '#') {
        ans++;
        dfs(i+1, j+1);
    }
    if(i-1 >= 0 and j-1 >= 0 and !vis[i-1][j-1] and v[i-1][j-1] == '#') {
        ans++;
        dfs(i-1, j-1);
    }
}
void solve(){
    cin >>  row  >> col;
    int start = -1, init = -1;
    bool f = true;
    memset(vis , 0 , sizeof(vis));
    for(int i = 0 ; i < row ; i++){
        cin >> v[i];
        for(int j = 0 ; j < col ; j++){
            if(v[i][j] == '#' and f ){
                start = i;
                init = j;
                f = false;
            }
        }
    }
    cout << start << "  " << init << sad;
    dfs(start , init);
    cout << ans << sad;
    ans = 0;
    v.clear();
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