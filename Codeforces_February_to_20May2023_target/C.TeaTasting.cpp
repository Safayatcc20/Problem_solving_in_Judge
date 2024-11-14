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
const long long N = 100000;
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
    long long n ;
    cin >>n ;
    vector<long long>a(n+1) , b(n+1), pre(n+1);
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(long long i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(long long i = 1; i <= n;  i++){
        pre[i] = pre[i-1] + b[i];
    }
    vector<long long>ans(n+5) , chk(n+5);
    for(long long i = 1; i <= n;  i++){
        int track = lower_bound(all(pre) , a[i] + pre[i-1])- pre.begin();
        //cout << track << sad;
        ans[i]++ , ans[track]--;
        chk[track] += a[i] + pre[i-1] - pre[track-1];
    }
    for(long long i= 1; i<= n ; i++){
        ans[i] += ans[i-1];
        //cout << chk[i] << sad;
        cout << ans[i] * b[i] + chk[i] << " ";
    }
    cout << sad;
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