//solved.

#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        long long x, y, k;
        cin >> x >> y >> k;
        long long ans;
        ans = k / x;
        if((ans * x + y <= k)){
            cout << ans * x + y << "\n";
        }
        else{
            cout << (ans - 1) * x + y << "\n";
        }
    }
}
