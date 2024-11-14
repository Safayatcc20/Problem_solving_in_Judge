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
    vector<long long>copy(n), v(n) , kopy(n);
    set<long long>s;
    vector<long long>zero , cz , kz;
    for(long long i = 0 ; i < n ; i++) {
        cin >> v[i];
        s.insert(v[i]);
    }
    if(s.size() == 1){
        cout << n - 1 << sad;
        return;
    }
    copy = v;
    kopy   = v;
    long long ft = 0 , sec = 0 , thrd = 0;
    for(long long i = 0; i < n ; i++){
        if(v[i] == 0){
            zero.push_back(i);
        }
    }
    for(long long i = 0; i < n ; i++){
        if(v[i] == 1){
            long long find = lower_bound(all(zero) , i+1) - zero.begin();
            ft += (zero.size() - find);
        }
    }
    for(long long i = 0; i < n ; i++){
        if(copy[i] == 0){
            copy[i] = 1;
            break;
        }
    }
    for(long long i = 0; i < n ; i++){
        if(copy[i] == 0){
            cz.push_back(i);
        }
    }
    for(long long i = 0; i < n ; i++){
        if(copy[i] == 1){
            long long find = lower_bound(all(cz) , i+1) - cz.begin();
            sec += (cz.size() - find);
        }
    }
    for(long long i = n; i >= 0 ; i--){
        if(kopy[i] == 1){
            kopy[i] = 0;
            break;
        }
    }
    for(long long i = 0; i < n ; i++){
        if(kopy[i] == 0){
            kz.push_back(i);
        }
    }
    for(long long i = 0; i < n ; i++){
        if(kopy[i] == 1){
            long long find = lower_bound(all(kz) , i+1) - kz.begin();
            //cout << find << sad;
            thrd += (kz.size() - find);
        }
    }
    //cout << ft << " " << sec << " " << thrd << sad; 
    cout << max({ft , sec , thrd}) << sad;
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