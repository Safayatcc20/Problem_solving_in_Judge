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
bool maxdistance(vector<long long>&v , long long c , long long dis){
    long long cnt = 1 , chk = v[0];
    for(int i = 1; i < v.size() ; i++){
        if(v[i] - chk < dis) continue;
        cnt++;
        chk = v[i];
    }
    if(cnt >= c) return true;
    else return false;
}
void solve(){
    int n ;
    cin >> n;
    vector<long long>v(n);
    for(auto &x:v) cin >> x;
    int c;
    cin >> c;
    long long ans = 0;
    sort(all(v));
    long long l = 0 , r = v[n-1];
    while(l <= r){
        long long mid = l + ( r - l ) / 2;
        if(maxdistance(v , c , mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
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