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
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        cout << "Case " << i << ": " ;
        i++;
        long long n , k;
        cin >> n >> k;
        vector<long long>v(n) , ans;
        for(auto &x:v) cin >> x;
        ans.push_back(v[0]);
        long long t = v[0];
        for(long long i = 1 ; i < n; i++ ){
            ans.push_back(t+1);
            t = t + v[i];
        }
        ans[0] = v[0] * k;
        for(long long i = 1 ; i < n; i++){
            if(v[i] > v[i-1]){
                ans[i] = ans[i] + (v[i] * k) - 1;
            }
            else if(v[i] <= v[i-1]){
                ans[i] = ans[i-1] + v[i];
            }
            //cout << ans[i] << " " ;
        }
        cout << ans[n-1] << sad;
    }
}