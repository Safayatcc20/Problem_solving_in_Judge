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
    vector<vector<long long>>v;
    for(long long i = 0 ; i < n; i++){
        vector<long long>vv;
        for(long long j = 0 ; j < n - 1; j++){
            long long x;
            cin >> x;
            vv.push_back(x);
        }
        v.push_back(vv);
    }
    map<long long , long long> mp;
    long long ft = 0 , last = 0;
    for(long long i = 0 ; i < n; i++){
        for(long long j = 0 ; j < 1 ; j++){
           // cout << v[i][j] << sad;
            mp[v[i][j]]++;
        }
    }
    long long mx = INT_MIN;
    for(auto &x:mp){
        if(mx < x.second){
            ft = x.first;
            mx  = x.second;
        }
    }
    //cout << ft << sad;
    map<long long , long long> mp1;
    for(long long i = 0 ; i < n; i++){
        for(long long j = n-2 ; j < n-1 ; j++){
           // cout << v[i][j] << sad;
            mp1[v[i][j]]++;
        }
    }
    long long mmx = INT_MIN;
    for(auto &x:mp1){
        if(mmx < x.second){
            last = x.first;
            mmx  = x.second;
        }
    }
    //cout << last << sad;
    long long take = 0 ;
    for(long long i = 0 ; i < n ; i++){
        for(long long j = 0 ; j < n - 1; j++){
            if(v[i][0] != ft and v[i][n-2] == last){
                take = i;
                break;
            }
        }
    }
    cout << ft << " ";
    for(long long i = take ; i < n; i++){
        for(long long j = 0 ; j < n- 1; j++){
            cout << v[i][j] << " ";
        }
        break;
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