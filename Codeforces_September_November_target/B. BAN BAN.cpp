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
void solve(){
    long long n;
    cin >> n;
    if(n ==1 ){
        cout << 1 << sad;
        cout << 1 << " " << 3 << sad;
        return;
    }
    if(n&1){
        cout << n /2 + 1 << sad;
        long long take = n /2 + 1 ;
        long long i  = 1;
        n *=3;
        while(take > 1){
            cout << i << " " << n << sad;
            i+=3;
            n-=3;
            take--;
        }
        cout << i << " " << n << sad;
    }
    else{
        cout << n / 2 << sad;
        long long take = n /2 ;
        long long i = 1;
        n*=3; 
        while(take--){
            cout << i << " " << n << sad;
            i+=3;
            n-=3;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}