/*
   **** Bismillahir Rahmanir Rahim ****
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
void solve()
{
    long long n ;
    cin >> n;
    set<long long> s;
    vector<long long > v(n);
    for(auto &x:v) {
        cin >> x;
    }
    long long ind = -1;
    reverse(v.begin() , v.end());
    map<long long , long long >mp;
    for(long long i = 0 ; i < n ;i++){
        if(mp[v[i]] != 1){
            mp[v[i]] = 1;
        }
        else{
            ind = i;
            break;
        }
    }
    if(ind == -1) ind = n;
    cout << n - ind << sad;
    /* for(auto &x:v){
        if(s.find(x) == s.end()){
            s.insert(x);
        }
        else{
            break;
        }
    } */
    //cout << n - s.size() << sad;
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