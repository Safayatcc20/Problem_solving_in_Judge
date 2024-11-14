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
    long long m;
    cin >> m;
    string s , t;
    cin >> s >> t;
    bool flag = false , fla = false;
    for(long long i = 0 ; i < m-1; i++){
        if(fla){
            if(t[i] == 'B' and t[i+1] == 'B'){
                continue;
            }
            else if(t[i] == 'B' and t[i+1] != 'B' and s[i] == 'B'){
                continue;
            }
            else if(s[i] == 'B' and s[i+1] == 'B'){
                fla = false;
                continue;
            }
            else if(s[i] == 'B' and s[i+1] != 'B' and t[i] == 'B'){
                fla = false;
                continue;
            }
            else{
                flag = true;
                cout << "2" << sad;
                break;
            }
        }
        else
        {
            if(s[i] == 'B' and s[i+1] == 'B'){
                continue;
            }
            else if(s[i] == 'B' and s[i+1] != 'B' and t[i] == 'B'){
                continue;
            }
            else if(t[i] == 'B' and t[i+1] == 'B'){
                fla = true;
                continue;
            }
            else if(t[i] == 'B' and t[i+1] != 'B' and s[i] == 'B'){
                fla = true;
                continue;
            }
            else{
                flag = true;
                cout << "1" << sad;
                break;
            }
        }
    }
    if(flag){
        na;
    }
    else{
        ha;
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