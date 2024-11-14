#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long x ;
    cin >> x;
    if(x % 2 == 0){
        if(!(x & (x-1))){
            cout << x + 1 << "\n";
        }
        else{
            cout << (x &~ (x-1)) << "\n";
        }
    }
    else{
        if(x > 1){
            cout << 1 ;
        }
        else{
            cout << 3;
        }
        cout << "\n";
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

