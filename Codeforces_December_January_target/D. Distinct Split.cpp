/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
long long t = 1;
void solve(){
    long long n ;
    cin >> n;
    string s;
    cin >> s;
    map<char , long long>mp;
    set<char>s1 , s2;
    long long ans = 0 , t = 0;
    vector<long long>a , b;
    for(long long i = 0 ; i < n ; i++){
        s1.insert(s[i]);
        a.push_back(s1.size());
    }
    for(long long i = n-1 ; i >= 0; i--){
        s2.insert(s[i]);
        b.push_back(s2.size());
    }
    reverse(all(b));
    for(long long i = 0 ; i < a.size() ; i++){
        //cout << a[i] << " " << b[i] << sad;
        ans = max(ans , (a[i] + b[i]));
        //mp[a[i] + b[i]]++;
    }
    long long mx = 0;
    for(auto &x:mp){
        if(mx <= x.second){
            mx = x.second;
            ans = x.first;
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