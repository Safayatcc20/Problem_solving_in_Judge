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
    int n ;
    cin >> n;
    string s , t , chk;
    cin >> s >> t;
    if(s == t){
        cout << 0 << sad;
        return;
    }
    reverse(all(t));
    if(s == (t)){
        cout << 2 << sad;
        return;
    }
    reverse(all(t));
    int ind = -1 ,ct = 0 ;
    for(int i = 0 ; i < n ;i++){
        if(s[i] != t[i]) {
            ct++;
            ind = i;
        }
    }
    chk = t;
    if(ct == 1){
        t[ind] = s[ind];
        if(s == t){
            cout << 1 << sad;
        }
        else cout << 2 << sad;
        return;
    }
    int j = n-1;
    int cnt1 = 0 , cnt2 = 0 ;
    for(int i = 0 ; i < n ;i++){
        if(s[i] != t[i]) cnt1++;
        if(s[i] != t[j-i]) cnt2++;
    }
    if(cnt1 & 1){
        cnt1 = cnt1 * 2 - 1;
    }
    else cnt1 *= 2;
    if(!(cnt2 & 1)){
        cnt2 = cnt2 * 2 - 1;
    }
    else cnt2 *= 2;
    cout << min(cnt2 , cnt1) << sad;
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