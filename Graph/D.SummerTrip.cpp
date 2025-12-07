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
const long long N= 1e7+10;
int cnt = 0 ;
vector<int>track(N+1);
bool cycle(long long source ,vector<bool>&vis,vector<bool>&curvis, vector<vector<long long>>&g){
    vis[source] = true;
    curvis[source] = true;
    cnt++;
    for(auto &x:g[source]){
        if(!vis[x]){
            if(cycle(x , vis , curvis,g)) return true;
        }
        else if(vis[x] == true and curvis[x] == true){
            return true;
        }
    }
    curvis[source] = false;
    track[source] = 1;
    return false;
}
void solve(){
    //dfs solution
    // finding the connected component then counting edges - node + connected component which is answer
    
   //Problem for DRMC contest try to solve D using it 
   // unsolve
   int n;
   cin >> n;
    vector<vector<long long>>g(n+2);
   for(int i = 1; i <= n; i++){
    int x;
    cin >>x;
    for(int j= 1; j <= x; j++){
        int v;
        cin >> v;
        g[i].push_back(v);
    }
   } 
    int ans = 0 ;
    vector<bool>vis(n , false) , curvis(n , false);
    for(int i = 1; i <= n ;i++){
        if(!vis[i]){
            if(cycle(i , vis , curvis , g) == false){
                //cout <<i << " ";
                //ha;
                //ans+= cnt;
            }
            //cnt = 0 ;
        }
    }
    for(int i = 1; i<= n;i++) if(track[i]) ans++;
    // int ans = 0;
    // vector<bool>vis(n , false) , curvis(n , false);
    // for(int i = 1; i <= n ;i++){
    //     if(!vis[i]){
    //         if(cycle(i , vis , curvis , g) ){
    //             //cout <<i << " ";
    //             ha;// Print there is at least a cycle 
    //             return;
    //             //ans+= cnt;
    //         }
    //         cnt = 0 ;
    //     }
    // }
    // Print how many nodes are connected with them 
    cout << ans << sad;
    
}
signed main()
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