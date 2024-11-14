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
constexpr bool multiple_test_cases = 1;
long long gcd(long long x, long long y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
long long lcm(long long x, long long y)
{
    return ((x * y) / gcd(x, y));
}
const long long N = 10000;
long long prime[N];
long long fact(long long n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
long long findXor(long long n){//reming: function calling findXor(sending value - 1);
    long long rest = n % 4;
    if(rest == 0) return n;
    if(rest == 1) return 1;
    if(rest == 2) return n+1;
    if(rest == 3) return 0;
}
void solve(){
    vector<string>v(10);
    for(int i =0 ; i < 10;i++){
        string s;
        cin >> s;
        v[i] = s;
    }
    int ans = 0 ;
    for(int i = 0; i < 10 ; i++){
        for(int j = 0; j < 10 ; j++){
            if(v[i][j] == 'X'){
                if(i == 0 || i == 9 || j == 0 || j == 9) ans++;
                else if(i == 1 || i == 8 || j == 1 || j == 8) ans+=2;
                else if(i == 2 || i == 7 || j == 2 || j == 7) ans+=3;
                else if(i == 3 || i == 6 || j == 3 || j == 6) ans+=4;
                else if(i == 4 || i == 5 || j == 4 || j == 5) ans+=5;
            }
        }
    }
    cout << ans << sad;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}