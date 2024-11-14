#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n ;
    if(n >= 10 && n < 100){
        cout << n % 10 << "\n";
    }
    else{
        vector<long long > v;
        while(n > 0){
            long long ans = n % 10;
            v.push_back(ans);
            n /= 10;
        }
        sort(v.begin() , v.end());
        cout << v[0] << "\n";
        }
}
int main()
{
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
