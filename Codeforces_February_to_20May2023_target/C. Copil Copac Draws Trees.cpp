
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
map<pair<long long , long long> , long long>mp;
long long give(vector<vector<long long >>&a , long long start, int val){
    long long ans = 0;
    for(long long j = 0 ; j < a[val].size() ; j++){
        if(a[val][j] == start) continue;
        else{
            if(mp[{start , val}] > mp[{val , a[val][j]}]){
                ans = max(ans , 1 + give(a , val , a[val][j]));
            }
            else ans = max(ans , give(a , val , a[val][j]));
        }
    }
    return ans;
}
void solve(){
    long long n ;
    cin >> n ;
    vector<vector<long long>>v(n+1);
    mp.clear();
    for(long long i = 0 ; i < n - 1 ; i++){
        long long x, y;
        cin >> x >> y;
        mp[{x , y}] = i;
        mp[{y , x}] = i;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    long long ans = INT_MIN;
    for(long long i = 0;  i < v[1].size() ; i++){
        ans = max(ans , give(v , 1 , v[1][i]));
    }
    cout << ans + 1 << sad;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}