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
void solve(){
    int n ;
    cin >> n;
    vector<vector<long long>>v(n , vector<long long>(n));
    long long sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >>v[i][j];
            sum += v[i][j];
        }
    }
    long long j = n- 1 , mn = INT_MAX;
    for(int i = 0 ; i < n ; i++){
        mn = min(mn , v[i][j]);
        j--;
    }
    cout << sum - mn << sad;
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