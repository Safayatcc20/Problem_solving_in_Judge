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
    long long n , k;
    cin >> n >> k;
    vector<long long>v(n+1);
    string s , t;
    cin >> s >> t;
    bool flag = true;
    for(long long i  = 0; i < n ; i++){
        if(s[i] == t[i]) continue;
        else if(s[i] == t[i+3] and i + 3 < n || s[i] == t[i+4] and i + 4 < n) continue;
        else if(s[i] == t[i-3] and i - 3 >= 0 || s[i] == t[i-4] and i - 4 >= 0 ) continue;
        else if((s[i] == t[i-1] and i -1 >= 0 || s[i] == t[i+1] and i+1 < n) and flag){
            cout << i << sad;
            flag = false;
            continue;
        }
        else if(flag == false){
            if(s[i] == t[i-1] and s[i-1] == t[i-2]){
                cout << i << sad;
                continue;
            }
            else if(s[i] == t[i+1] and s[i-1] == t[i]){
                cout << i << sad;
                continue;
            }
        }
        else {
            //cout << i << sad;
            na;
            return;
        }
    }
    ha;
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