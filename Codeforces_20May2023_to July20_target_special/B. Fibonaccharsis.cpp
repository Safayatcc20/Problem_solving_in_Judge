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
 
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    cin >> t;
    vector<array<long long , 2>>v(35);
    array<long long , 2 > ft = {1 , 0}, sec = {0 , 1};
    v[1] = ft;
    v[2] = sec;
    for(long long i = 3; i < 35; i++){
        ft = v[i-2];
        sec = v[i-1];
        array<long long , 2>fibo;
        fibo[0] = ft[0] + sec[0];
        fibo[1] = ft[1] + sec[1];
        v[i] = fibo;
        ft = sec;
        sec = fibo;
    }
    while (t--)
    {
        long long n , k;
        cin >> n >> k;
        if(k > 900) {
            cout << 0 << sad;
            continue;
        }
        array<long long , 2>res = v[k];
        long long ans =  0;
        for(long long i = 0 ; i < n ; i++){
            long long temp = n - res[0] + i;
            if((temp) % res[1] == 0 ){
                if(temp / res[1] >= i) ans++;
            }
        }
        cout << ans << sad;
    }
}