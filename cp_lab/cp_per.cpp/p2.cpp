/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
long long t = 1;
const long long MOD = 1e9+7; 

long long power(long long x, long long n) {
    if (n == 0) {
        return 1;
    }
    long long y = power(x, n / 2);
    if (n % 2 == 0) {
        return (y * y) % MOD;
    } else {
        return (((y * y) % MOD) * x) % MOD;
    }
}
void solve(){
    string s;
    cin >> s;
    long long cnt = 0;
    for(auto &x:s){
        if(x == '1') cnt++;
    }
    cout <<  power(3 , cnt) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}