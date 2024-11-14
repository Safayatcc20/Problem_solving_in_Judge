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
    long long a,  b , m , n ;
    cin >> a >> b >> m >> n;
    a -= m;
    b -= n;
    a = abs(a) , b = abs(b);
    sieve();
        vector<long long>v;
        v.push_back(1);
        map<long long , long long>mp;
        if(a % 2 == 0 and b % 2 == 0)  {
            v.push_back(2);
            if(2 * 2 != a ){
                v.push_back(a / 2);
                mp[a / 2] = 1;
            }
            if(2 * 2 != b){
                if(!mp[b / 2]){
                    v.push_back(b / 2);
                    mp[b/2] = 1;
                }
            }
        }
        for(long long i = 3; i* i <= min(a , b); i+= 2){
            if(a % i == 0 and b % i == 0 and isprime(i)){
                v.push_back(i);
                mp[v[i]] = 1;
                if(i * i != a and mp[a / i] == 0){
                    v.push_back(a / i);
                    mp[a / i] = 1;
                }
                if(i * i != b and mp[b / i] == 0){
                    v.push_back(b / i);
                    mp[b / i] = 1;
                }
            }
        }
        long long chk = max(m , n);
        for(long long i = 0 ; i < v.size() ; i++){
            if(v[i] > chk){
                cout << v[i] << sad;
                return;
            }
        }
        //cout << v.size() << sad;
        cout << - 1 << sad;
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