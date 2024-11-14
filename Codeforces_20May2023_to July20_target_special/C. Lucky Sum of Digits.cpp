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
    if(n == 4 || n == 7){
        cout << n << sad;
        return;
    }
    int m = 1e7+5;
    int four = 0 , four1 = 0, seven1 = 0, seven = 0 , rem  = INT_MAX;
    
    for(int i = 1;  i < m ; i++){
        if(n - (i * 7) >= 0 and (n - (i * 7)) % 4 == 0){
            four = (n - (i * 7))/4;
            seven = i;
            //cout << seven << " "<< four << sad;
            if(seven + four <= rem){
                seven1 = seven;
                four1 = four;
                rem = seven1 +four1;
            }
        }
    }
    //cout << four1 << " "<< seven1 << sad;
    for(int i = 1;  i < m ; i++){
        if(n - (i * 4) >= 0 and (n - (i * 4)) % 7 == 0){
            seven = (n - (i * 4))/7;
            four = i;
            //cout << seven << " "<< four << " "<< seven + four << sad;;
            if(seven + four <= rem){
                seven1 = seven;
                four1 = four;
                rem = seven1 +four1;
            }
        }
    }
    //cout << four1 << " "<< seven1 << sad;
    string ans;
    four = four1 , seven = seven1;
    if(four == 0 and seven == 0){
        cout << - 1<< sad;
        return;
    }
    else{
        four = four1 , seven = seven1; 
        while (four--)
        {
            cout << '4';
        }
        while (seven--)
        {
            cout << 7;
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