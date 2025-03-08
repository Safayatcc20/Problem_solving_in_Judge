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
bool searh(long long x, vector<vector<long long>>&v , long long n){
    long long l = 0  , h = n*n - 1;
    while( l < h){
        long long mid = (l + h) / 2;
        long long tc = mid % n;
        long long tr = mid / n;
        if(v[tr][tc] == x) return 1;
        if(v[tr][tc] < x){
            l = mid+1;
        }
        else{
            h = mid - 1;
        }
    }
    return 0;
}
void solve(){
    long long n;
    cin >> n;
    vector<vector<long long>>v(n , vector<long long>(n));
    for(long long i = 0 ;i < n; i++){
        for(long long j = 0 ; j < n ; j++){
            cin >> v[i][j];
        }
    }
    /* for(long long i = 0 ;i < n; i++){
        for(long long j = 0 ; j < n ; j++){
            cout <<  v[i][j] << " ";
        }
        cout << endl;
    } */
    long long x;
    cin >> x;
    if(searh(x , v , n) ){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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