#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n , m;
    cin >> n >> m ;
    vector<long long>a(n) , b(m);
    for(auto &x: a){
        cin >> x;
    }
    sort(a.begin() , a.end());
    for(auto &x: b){
        cin >> x;
    }
    for(auto &x: b){
        long long y = upper_bound(a.begin() , a.end() , x) - a.begin();
        cout << y << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //long long t;
    //cin >> t;
    //while(t--){
        solve();
    //}
}

