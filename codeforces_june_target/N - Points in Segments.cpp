#include<bits/stdc++.h>
using namespace std;
void solve(long long cas)
{
    long long n , m;
    cin >> n >> m ;
    vector<long long>a(n) , b(m);
    for(auto &x: a){
        cin >> x;
    }
    cout << "Case "<< cas << ":\n";
    sort(a.begin() , a.end());
    while(m--){
        long long l , h;
        cin >> l >> h;
        long long y = lower_bound(a.begin() , a.end() , l) - a.begin();
        long long z = upper_bound(a.begin() , a.end() , h) - a.begin();
        cout << z - y << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    long long cas = 0;
    for(long long i = 1; i<= t; i++){
        solve(i);
    }
}

