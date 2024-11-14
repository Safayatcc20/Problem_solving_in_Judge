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
void solve(){
    long long n ;
    cin >> n;
    set<long long>s;
    s.insert(0);
    long long cnt  = 0 , sum = 0;
    while (n--)
    {
        /* code */
        long long t; 
        cin >> t;
        sum += t;
        //cout << sum << sad;
        if(s.count(sum)){
            //cout << s.count(sum) << sad;
            cnt++;
            s.clear();
            s.insert(0);
            sum = t;
            s.insert(sum);
        }
        else{
            s.insert(sum);
        }
    }
    cout << cnt << sad;
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    // long long t;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}