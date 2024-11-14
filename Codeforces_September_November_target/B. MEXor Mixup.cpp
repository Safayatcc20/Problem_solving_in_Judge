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

long long findXor(long long n){
    long long rest = n % 4;
    if(rest == 0) return n;
    if(rest == 1) return 1;
    if(rest == 2) return n+1;
    if(rest == 3) return 0;
}
const long long n = 3e5+7;
vector<long long>v(n , 0);
void got(){
    for(long long i = 1; i <= n ; i++){
        v[i-1] = v[i-1] ^ i;
    }
}
void solve(){
    long long a , b;
    cin >> a >> b;
    long long chk = findXor(a-1);
    if(chk == b){
        cout << a << sad;
    }
    else if((chk ^ b) != a){
        cout << a + 1 << sad;
    }
    else{
        cout << a + 2 << sad;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    got();
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}