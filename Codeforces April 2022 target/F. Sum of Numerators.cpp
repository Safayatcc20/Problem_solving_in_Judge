


#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n, k, sum = 0;
    cin >> n >> k;
    sum = (n * (n + 1) ) / 2;
    while(n > 1 && k > 0){
        n /= 2;
        k--;
        sum -= (n * ( n + 1 )) / 2;
    }
    cout << sum << "\n";
}
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}

