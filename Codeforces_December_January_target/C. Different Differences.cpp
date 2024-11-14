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
    long long n , k;
    cin >> k >> n;
    if(n == k){
        for(int i = 1; i <= k  ; i++){
            cout << i << " ";
        }
        cout << sad;
        return;
    }
    vector<int>v, chk;
    v.push_back(1);
    v.push_back(2);
    chk.push_back(1);
    map<long long , long long>mp;
    mp[v[0]] = 1;
    mp[v[1]] = 1;
    long long c = 1;
    for(int i = 2; i <= n ; i++){
        if(v[c] + i > n || v.size() == k) break;
        v.push_back(v[c] + i);
        mp[v[c] + i]  = 1;
        c++;
    }
    for(int i = n ; i>  0 ; i--){
        if(v.size() == k) break;
        if(mp[i] != 1){
            v.push_back(i);
            mp[i] = 1;
        }
    }
    sort(all(v));
    for(int i = 0 ; i < k ; i++){
        cout << v[i] << " ";
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