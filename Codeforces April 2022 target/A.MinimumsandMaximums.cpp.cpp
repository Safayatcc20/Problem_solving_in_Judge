#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long l1 , r1 , l2 , r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if((l1<= r2 && l2 <= r1)){
        cout << max(l1, l2) << "\n";
    }
    else{
        cout << l1 + l2 << "\n";
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