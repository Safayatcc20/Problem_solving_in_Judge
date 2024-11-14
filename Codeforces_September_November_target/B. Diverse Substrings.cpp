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
    string s;
    cin >> s;
    long long ans = 0 , mx = 101;
    for(long long i = 0 ;  i < n ;i++){
        long long cnt = 0, maxi = 0 ;
        map<char , long long>occur;
        for(long long j = i ; j < min(n , i+ mx);j++){
            occur[s[j]]++;
            //cout << occur.size() << sad;
            maxi = max(maxi , occur[s[j]]);
            if(maxi <= occur.size()){
                ans++;
            }
        }
    }
    cout << ans << sad;
    //my solution whcich is ac within the contest time
    /* long long n ;
    cin >> n;
    string s;
    cin >> s;
    set<char>ss;
    long long ans = 0 , j = 1 , mx = 101;
    for(long long i = 0 ;  i < n ;i++){
        long long cnt = 0 ;
        map<char , long long>occur , mp;
        string go ;
        for(int j = i ; j < min(n , i+ mx);j++){
            go+=s[j];
            occur[s[j]]++;
            ss.insert(s[j]);
            if(mp[s[j]] != 1){
                mp[s[j]] = 1;
                cnt++;
            }
            bool flag = true;
            for(auto &x:ss){
                if(occur[x] > cnt){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans++;
                //cout << go << sad;
            }
        }
        ss.clear();
    }
    cout << ans << sad; */
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