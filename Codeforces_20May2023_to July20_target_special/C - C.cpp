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
    string s;
    cin >> s;
    if(s.size() < 2){
        cout << s << sad;
        return;
    }
    sieve();
    set<int>ss;
    vector<int>v;
    for(int i = 0 ; i < s.size() ; i++){
        //cout << s[i] - '0' << sad;
        int x = s[i] - '0';
        v.push_back(s[i] - '0');
        if(isprime(x)){
            ss.insert(x);
            if(ss.size() > 1){
                cout << 1 << sad;
                return;
            }
        }
    }
    sort(all(v));
    int x = v[0];
    for(int i = 1; i < v.size() ; i++){
        /* if(v[i] % x != 0){
            cout << 1 << sad;
            return;
        } */
        x = gcd(x , v[i]);
    }
    cout << x << sad;
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