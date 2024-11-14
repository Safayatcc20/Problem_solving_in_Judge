/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
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
    long long n; 
    cin >> n;
    vector<string>v;
    v.push_back("ABSINTH");
    v.push_back("BEER");
    v.push_back("BRANDY");
    v.push_back("CHAMPAGNE");
    v.push_back("GIN");
    v.push_back("RUM");
    v.push_back("SAKE");
    v.push_back("VODKA");
    v.push_back("TEQUILA");
    v.push_back("WHISKEY");
    v.push_back("WINE");
    v.push_back("0");
    v.push_back("1");
    v.push_back("2");
    v.push_back("3");
    v.push_back("4");
    v.push_back("5");
    v.push_back("6");
    v.push_back("7");
    v.push_back("8");
    v.push_back("9");
    v.push_back("10");
    v.push_back("11");
    v.push_back("12");
    v.push_back("13");
    v.push_back("14");
    v.push_back("15");
    v.push_back("16");
    v.push_back("17");
    long long ans = 0 ;
    bool age = 0 , alco = 0;
    for(long long i = 0 ; i < n ; i++){
        string s;
        cin >> s;
        for(long long j = 0; j < v.size() ; j++){
            if(s == v[j]){
                //cout << v[j] << sad;
                ans++;
                break;
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
    //cin >> t;
    while (t--)
    {
        solve();
    }
}