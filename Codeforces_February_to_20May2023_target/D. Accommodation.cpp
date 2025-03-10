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
    vector<string>v(n);
    for(auto &x:v) cin >> x;
    long long mx = 0 , mn = 0;
    for(long long i = 0 ; i < n;  i++){
        string s = v[i];
        for(long long j = 0 ; j < m ; j++){
            if(s[j] == '1'){
                mn++ , mx++;
            }
        }
    }
    for(long long i = 0 ; i < n;  i++){
        long long two = m / 4;
        string s = v[i];
        for(long long j = 0 ; j < m -1;j++){
            if(s[j] == '1' and s[j+1] == '1'){
                mn--;two--;
                j++;
                if(!two){
                    break;
                }
            }
        }
    }
    for(long long i = 0 ; i < n;  i++){
        long long two = m / 4;
        string s = v[i];
        for(long long j = 0 ; j < m-1 ;j++){
            if(s[j] == '0'){
                two--;j++;
                if(!two){
                    break;
                }
            }
            else if(s[j] == '1' and s[j+1] == '0'){
                j++ , two--;
                if(!two) break;
            }
        }
        mx -= two;
    }
    cout << mn << " " << mx << sad;
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