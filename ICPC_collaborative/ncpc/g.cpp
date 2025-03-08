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
#define int long long
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
    int n;
    cin >> n;
    vector<int>a(n) ,b(n);
    for(auto &x:a) cin >> x;
    for(auto &x:b) cin >> x;
    if(a == b){
        cout << 0 << sad;
        return;
    }
    map<int , set<int>>mp;
    for(int i = 0 ; i < n ;i++){
        mp[a[i]].insert(i);
    }
    int ans = 0 , cnt  = 0 ;
    bool f = true;
    /* if(mp[b[0]] == 0){
        bool ok = false;
        for(int i = 1; i < n ; i++){
            if(mp[b[i]] ){
                ok = true;
            }
            else{
                if(ok){
                    cout << n << sad;
                    return;
                }
                ans++;
                continue;
            }
        }
        if(ok == false){
            cout << n << sad;
        }
        else {
            cout << ans + 1 << sad;
        }
    }
    else{
        
    } */
    int ans = 0 ;
    int l = -1;
    for(int i = 0 ; i < n ; i++){
        if(mp[b[i]].size() > 0){
            l = i;
            break;
        }   
    }
    if(l != -1){
        if(mp[b[n-1]].size() == 0 and n > 2){
            cout << 0 << sad;
        }
        else{
            cout << 
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    cin >> t;
    int i= 1;
    while (t--)
    {
        cout << "Case " << i << ": ";
        i++;
        solve();
    }
}