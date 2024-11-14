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
const long long N = 1e7 + 10;
bool prime[N];
void sieve()
{
    prime[1] = prime[0] = true;
    for (long long i = 3; i * i <= N; i += 2)
    {
        if (prime[i])
        {
            continue;
        }
        for (long long j = i * i; j < N; j += i + i)
        {
            prime[j] = true;
        }
    }
}
bool isprime(long long x)
{
    if (x == 2)
        return true;
    else if ((x % 2 == 0))
        return false;
    return !prime[x];
}
void solve(){
    sieve();
    int n;
    cin >> n;
    set<int>s;
    vector<int>a(n) , b(2e6+5) , d(2e6+5);
    int mx = 0;
    for(int i = 0 ; i< n ;i++){
        cin >> a[i];
        s.insert(a[i]);
    }
    for(int i = 0 ; i< n ;i++){
        int x;
        cin >> x;
        b[a[i]] = x;
    }
    int m;
    cin >> m;
    vector<int>c(m);
    for(int i = 0 ; i< m;i++){
        cin >> c[i];
        s.insert(c[i]);
    }
    int mod = 998244353;
    for(int i = 0 ; i< m;i++){
        int x;
        cin >> x;
        d[c[i]] = x;
    }
    int ans = 1;
    if(b[2] < d[2]){
        cout << 0 << sad;
        return;
    }
    for(auto &x:s){
        if(b[x] < d[x]){
            cout << 0 << sad;
            return;
        }
        if(b[x] > d[x]) ans = (ans * 2) % mod;
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