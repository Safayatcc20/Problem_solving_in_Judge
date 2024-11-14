/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.rbegin(), b.rend()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
long long t = 1;
void solve(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n , k;
    cin >> n >> k;
    vector<pair < int , int>>v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i].first;
        v[i].second = i+1;
    }
    sort(all(v));
    cout << v[k-1].first << sad;
    for(int i = k - 1; i >= 0; i--){
        cout << v[i].second << " ";
    }
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