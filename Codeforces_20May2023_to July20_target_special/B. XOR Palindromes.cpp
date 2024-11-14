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
    long long n;
    cin >> n ;
    string s , t;
    cin >> s;
    vector<long long>ind;
    for(long long i = 0 ; i < n / 2; i++) {
        if(s[i] != s[n - i - 1]) ind.push_back(i);
    }
    for(long long i = 0 ; i <= n ;i++) t+='0';
    //cout << t << sad;
    long long cal = (n - 2 * ind.size())/ 2, m = ind.size();
    t[m] = '1';
    if(n & 1){
        while(cal>= 0){
            t[m] = '1';
            if(m+1 <= n) t[m+1] = '1';
            m+=2;
            cal--;
        }
    }
    else{
        while(cal>= 0){
            t[m] = '1';
            m+=2;
            cal--;
        }
    }
    cout << t << sad;
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