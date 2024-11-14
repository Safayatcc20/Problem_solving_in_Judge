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
    //1, 5, 10, 50, 100, 500.;
    vector<long long>v(6);
    v.push_back(1);
    v.push_back(5);
    v.push_back(10);
    v.push_back(50);
    v.push_back(100);
    v.push_back(500);
    map<long long , long long >mp;
    while(n > 0){
        if(n >= 500){
            mp[500]++;
            n-= 500;
        }
        else if(n >= 100){
            mp[100]++;
            n-= 100;
        }
        else if(n >= 50){
            mp[50]++;
            n-= 50;
        }
        else if(n >= 10){
            mp[10]++;
            n-= 10;
        }
        else if(n >= 5){
            mp[5]++;
            n-= 5;
        }
        else if(n >= 1){
            mp[1]++;
            n-= 1;
        }
        if(n == 0){
            break;
        }
    }
    for(auto &x:v){
        while(mp[x]){
            cout << x << " ";
            mp[x]--;
        }
    }
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