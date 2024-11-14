#include<bits/stdc++.h>
using namespace std;
#define all(n) n.begin(),n.end()
void solve()
{
    long long n;
    cin >> n;
    vector<long long> v(n), b(n);
    for(long long i = 0 ;i < n;i++){
        cin >> v[i];
        b[i] = v[i];
    }
    reverse(all(b));
    if(is_sorted(all(v))){
        cout << 0 << "\n";
    }
    else if(is_sorted(all(b))){
        cout << n / 2 << "\n";
    }
    else{
        long long cnt = 0 , i = 0;
        while(i+1 < n){
            if(v[i] > v[i+1]){
                cnt++;
                i++;
            }
            i++;
        }
        cout << cnt << "\n";
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

