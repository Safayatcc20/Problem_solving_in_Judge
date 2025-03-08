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
    if(i+1 < row and !vis[i+1][j] and v[i+1][j] == '.') {
        ans++;
        dfs(i+1 , j);
    }
    if(i-1 >= 0 and !vis[i-1][j] and v[i-1][j] == '.') {
        ans++;
        dfs(i-1 , j);
    }
    if(j+1 < col and !vis[i][j+1] and v[i][j+1] == '.') {
        ans++;
        dfs(i , j+1);
    }
    if(j-1 >= 0 and !vis[i][j-1] and v[i][j-1] == '.') {
        ans++;
        dfs(i , j-1);
    }
}
void solve(){
    cin >> col >> row;
    int start = -1 , init = -1;
    memset(vis , 0 , sizeof(vis));
    for(int i = 0 ; i < row ; i++){
        cin >> v[i];
        for(int j = 0 ;j  < col ; j++){
            if(v[i][j] == '@'){
                start = i;
                init = j;
            }
        }
    }
    dfs(start , init);
    cout << ans << sad;
    ans = 1;
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
    int i= 1;

    while (t--)
    {
        cout << "Case " << i << ": ";
        i++;
        solve();
    }
}