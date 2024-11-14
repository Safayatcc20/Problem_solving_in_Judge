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
    int x , y , n;
    cin >> x >> y >> n;
    vector<int>v(n);
    v[0] = x , v[n-1] = y;
    int k = 1;
    for(int i = n - 2 ; i> 0; i--){
        v[i] = y-k;
        y = v[i];
        k++;
    }
    
    map<int  , int>mp;
    int track = INT_MAX;
    for(int i = 0 ; i < n-1 ;i++){
        if(v[i] >= v[i+1]) {
            minusone;
            //cout << 1 << sad;
            return;
        }
        else if(mp[v[i+1] - v[i]]){
            //cout << 2 << " " << i  << sad;
            minusone;
            return;
        }
        if(track <= v[i+1] - v[i]){
            minusone;
            return;
        }
        track = v[i+1] - v[i];
        mp[v[i+1] - v[i]] = 1;
    }
    for(auto &x:v) cout << x <<  "  ";
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