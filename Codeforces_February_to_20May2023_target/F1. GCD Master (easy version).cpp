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
bool chk(long long n){
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    sieve();
    if(prime[n]) return false;
    else return true;
}
long long findXor(long long n){//reming: function calling findXor(sending value - 1);
    long long rest = n % 4;
    if(rest == 0) return n;
    if(rest == 1) return 1;
    if(rest == 2) return n+1;
    if(rest == 3) return 0;
}
void solve(){
    long long n , m , k ; 
    cin >> n >> m >> k;
    vector<long long>v(n);
    for(auto &x:v) cin >> x;
    vector<long long>vv;
    for(long long i = 0; i < n; i++){
        if(chk(v[i])){
        vv.push_back(v[i]);
        }
    }
    sort(all(vv));
    map<long long , long long>mp;
    long long g = 0 ;
         long long cnt = 0 ;
    if(vv.size() >= 2){
         g = gcd(vv[vv.size()-1] ,vv[vv.size()-2]);
         mp[vv[vv.size()-1]] = 1;
         mp[vv[vv.size()-2]] = 1;
        for(long long i = vv.size()-3; i >= 0; i--){
            cnt++;
            g = gcd(g , vv[i]);
            mp[vv[i]] = 1;
            if(cnt == k) break;
        }
        //cout << g << sad;
    }
    long long sum = 0;
    cnt = 0;
    for(long long i  = 0 ; i < n ; i++){
        if(mp[v[i]] == 1 and cnt <= k) {cnt++;continue;}
        else sum += v[i];
    }
    cout << g + sum << sad;
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