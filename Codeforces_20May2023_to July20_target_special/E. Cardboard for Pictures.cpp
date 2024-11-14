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
    int n ;
    cin >> n;
    long long c ;
    cin >> c;
    vector<long long>v(n);
    long long total = 0 , side = 0;
    for(int i = 0 ; i < n ;i++){
        cin >> v[i];
        total += (v[i] * v[i]);
        side += v[i];
    }
    long long rem = c - total;
    rem /= (4 * n);
    side = side / (2 * n);
    //cout << rem << " " << side <<  sad;
    long long ans = sqrtl(side * side + rem) ;
    cout << ans - side << sad;
    /* long long l = 0, r = c;
    long long ans = 0 ;
    while( l <= r){
        long long mid = (r + l ) / 2;
        long double chk = 0 ;
        //cout << mid << sad;
        for(long long i = 0 ; i < n ; i++){
            chk += ((long double)((2 * mid + v[i]) * (2*mid + v[i])));
        }
        //cout << chk << sad;
        if(chk <= c){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout << ans << sad;  */
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