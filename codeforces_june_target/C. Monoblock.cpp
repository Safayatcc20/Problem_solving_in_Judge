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
void solve()
{
    long long n;
    cin >> n ;
    long long m;
    cin >> m;
    vector<long long >v(n);
    for(auto &x : v) cin >> x;
    while(m--){
        long long i  , x;
        cin >> i >> x;
        i--;
        v[i] = x;
        long long sum = 0;
        for(long long i = 0 ; i < n ; i++){
            set<long long>s;
            for(long long j = i ; j < n ; j++){
                s.insert(v[j]);
                sum += s.size();
            }
        }
        cout << sum << sad;
    }
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    //cin >> t;
    //while(t--){
        solve();
    //}
}