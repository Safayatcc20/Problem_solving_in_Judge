#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    vector<long long>v(n);
    vector<long long> even;
    long long odd = 0,ans = 0;
    for(auto &x:v){
        cin >> x;
        if(x % 2 != 0){
            odd++;
        }
        else{
            if(x % 4 != 0){
                ans++;
                odd++;
            }
            else{
                even.push_back(x);
            }
        }
    }
    if(odd > 0){
        cout << ans + even.size() << "\n";
    }
    else{
        long long mn = INT_MAX ,cnt = 0;
        for(auto &x : even){
            while(x % 4 == 0){
                cnt++;
                x /= 2;
            }
            mn = min(mn , cnt);
            cnt = 0;
        }
        cout << mn + even.size()  << "\n";
    }
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

