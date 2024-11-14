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
    int a[n][n];
    a[0][0] = 1;
    map<long long , long long>mp;
    vector<long long>v;
    int r = 1 , t = n * n;
    for(long long i = 0 ; i < n * n; i++){
        if(i & 1){
            v.push_back(t);t--;
        }
        else {
            v.push_back(r)  ; r++;
        }
    }
    int nxt = 0;
    for(long long i = 0 ;i < n  ;i++){
        if(i & 1){
            for(long long j =  0 ;  j < n ; j++){
                a[i][j] = v[nxt];
                nxt++;
            }
        }
        else{
            for(long long j =  n-1 ;  j > -1 ; j--){
                a[i][j] = v[nxt];
                nxt++;
            }
        }
    }
    for(long long i = 0 ; i < n ; i++){
        for(long long j = 0 ; j < n ; j++){
            cout << a[i][j] << " ";
        }
        cout << sad;
    }
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