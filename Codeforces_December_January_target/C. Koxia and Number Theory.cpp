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
    long long n ;
    cin >> n;
    vector<long long>v(n);
    for(long long i = 0 ; i < n; i++){
        cin >> v[i];
    }
    long long l = 0, r = 1000;
    while(l <= r){
        long long mid = l + (r - l) / 2;
        bool flag = true;
        for(long long i = 0 ; i < n ; i++){
            for(long long j = i + 1; j < n ;j++){
                if(gcd(v[i]+ mid , v[j] + mid)!= 1){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            ha;
            return;
        }
        r = mid-1;
    }
    r = 1000;
    while(l <= r){
        long long mid = l + (r - l) / 2;
        bool flag = true;
        for(long long i = 0 ; i < n ; i++){
            for(long long j = i + 1; j < n ;j++){
                if(gcd(v[i]+ mid , v[j] + mid)!= 1){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            ha;
            return;
        }
        l = mid+1;
    }
    
    na;
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