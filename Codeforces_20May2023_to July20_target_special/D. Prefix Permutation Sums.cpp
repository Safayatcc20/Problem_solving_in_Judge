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
    long long n;
    cin >> n;
    vector<long long> v;
    set<long long>s;
    map<long long , long long>mp;
    for(long long i = 0 ; i < n - 1 ; i++) {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    if((n * (n + 1)) / 2 < v[n-2]) {
        na;
        return;
    }
    if(v[n-2] != (n*(n+1))/2){
        v.push_back((n*(n+1))/2);
        vector<long long >present;
        present.push_back(v[0]);
        for(int i = 1; i< n; i++){
            present.push_back(v[i] - v[i-1]);
        }
        for(int i = 0 ; i < n; i++){
            if(present[i] < 1 || present[i] > n){
                na;
                return;
            }
            s.insert(v[i]);
        }
        if(s.size() == n){
            ha;
        }
        else{
            na;
        }
        return;
    }
    vector<long long >present;
    present.push_back(v[0]);
    if(v[0] <= n){
        mp[v[0]] = 1;
    }
    for(int i = 1; i < n-1; i++){
        present.push_back(v[i] - v[i-1]);
        if(v[i] - v[i-1] <= n){
            mp[v[i] - v[i-1]] = 1;
        }
    }
    vector<long long>miss;
    for(int i = 1; i <= n ; i++){
        if(mp[i]) continue;
        miss.push_back(i);
    }
    //cout << miss.size() << sad;
    if(miss.size() != 2){
        na;
        return;
    }
    for(int i = 0 ; i< present.size();i++){
        if(miss[0] + miss[1] == present[i]){            
            ha;
            return;
        }
    }
    na;
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