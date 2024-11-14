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
    long long cnt = 0 ;
    for(long long i = 0 ;i < n ; i++){
        long long x;
        cin >> x;
        while (x % 2 == 0)
        {
            /* code */
            cnt++;
            x /= 2;
        }        
    }
    if(cnt >= n){
        cout << 0 << sad;
        return;
    }
    vector<long long>store;
    for(long long i = 2; i <= n ;i++){
        long long go = i  , myvalueis = 0;
        while (go % 2 == 0)
        {
            /* code */
            myvalueis++;
            go /= 2;
        }
        if(myvalueis > 0){
            store.push_back(myvalueis);
        }
    }
    sort(all(store));
    long long ans = 0;
    for(long long i = store.size() - 1; i >= 0 ; i--){
        cnt += store[i];
        ans++;
        if(n - cnt <= 0){
            break;
        }
    }
    //cout << cnt << sad;
    if(n - cnt > 0){
        cout << -1 <<sad;
    }
    else{
        cout << ans << sad;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}