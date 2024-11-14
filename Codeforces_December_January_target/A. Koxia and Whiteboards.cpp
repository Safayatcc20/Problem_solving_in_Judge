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
    long long n , m;
    cin >> n >> m;
    vector<long long>v(n) , vv(m);
    for(long long i = 0 ;  i < n ; i++){
        cin >> v[i];
    }
    sort(all(v));
    long long sum = 0 , take  = m ;
    for(long long i = 0 ; i < m ; i++){
        cin >> vv[i];
    }
    for(long long i = 0 ; i < m ; i++){
        bool flag = true;
        for(long long j  = 0; j < n ; j++){
            if(v[j] < vv[i]) {
                flag = false;
                v[j] = vv[i];
                
                break;
            }
        }
        if(flag){
            if(i < n)
            v[i] = vv[i];
            else
            v[0] = vv[i];
        }
        sort(all(v));
    }
    for(long long i = 0 ; i < n ; i++){
        sum += v[i];
    }
    cout << sum << sad;
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