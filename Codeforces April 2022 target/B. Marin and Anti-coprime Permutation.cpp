#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    if(n % 2 != 0){
        cout << 0 << "\n";
    }
    else{
        long long fact = 1;
        n = n / 2;
        for(long long i = 2; i <= n; i++){
            fact *= i * i % 998244353;
            fact %= 998244353;
        }
        cout << fact << "\n";
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
