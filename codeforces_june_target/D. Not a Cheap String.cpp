/*
   **** Bismillahir Rahmanir Rahim ****
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
long long t = 1;
long long cond(pair<char , long long> &a , pair<char  , long long > &b){
    return(a . first > b.first);
}
void solve()
{
    string s;
    cin >> s;
    long long n;
    cin >> n;
    vector<pair<char , long long>> v;
    vector<long long>vv(s.size() + 1, 0);
    long long sum = 0;
    for(long long i = s.size() - 1; i >= 0; i--){
        v.push_back({s[i]  , i});
        sum += s[i] - 'a' + 1;
    } 
    sort(all(v) , cond);
    for(auto &x:v){
        if(sum <= n) break;
        sum -= x.first - 'a' + 1;
        vv[x.second] = - 1;
    }
    for(long long i = 0 ; i <  s.size(); i++){
        if(vv[i] != -1){
            cout << s[i];
        }
    }
    cout << sad;
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}