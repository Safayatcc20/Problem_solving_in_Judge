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
    long long n;
    cin >> n;
    vector<long long>v(n), vv(n);
    for(long long i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    vv = v;
    sort(all(vv));
    long long a =  0 , b = 0 , c = 0;
    for(long long i = 0; i < n ;i++){
        long long sum = 0, cnt = 0;
        for(long long j = 0; j < n ; j++){
            if(i == j) continue;
            sum = v[j];
            for(long long k = 0 ; k < n ;k++){
                if(k == i)continue;
                if(k == j)continue;
                //cout << sum + v[k] << " " << v[i] << sad;
                if(sum + v[k] == v[i]){
                    a = i+1 , b =  j + 1 ,  c = k + 1;
                    cout << a << " " << b << " " << c << sad;
                    return;
                }
            }
        }
    }
    cout << -1 << sad;
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