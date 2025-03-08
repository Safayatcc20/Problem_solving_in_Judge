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
    long long n , a , b ;
    cin >> n >> a >> b;
    if( a== 1 || b == 1){
        cout << 0 << sad;
        return ;
    }
    long long cal = (n *(n+1))/ 2;
    if( a== 2 || b == 2){
        cal -= ((n/2) * ((2 + (n / 2)*2)) )/ 2;
        //cout << cal << sad;
        if(a == 2){
            a = b;
        }
        for(long long i = a; i<= n ; i+=a){
            if(i % 2){
                cal -= i;
            }
        }
        cout << cal << sad;
        return;
    }
    long long temp = a;
    a = min(a , b);
    b = max(temp , b);
    long long aa = n / a , bb = n / b;
    long long ca = (aa*(2*a+(aa-1)*a))/2;
    for(long long i = b ; i <= n ; i+=b){
        if(i % a != 0){
            cal -=i;
        }
    }
    //cout << cal << " " << ca << " "  << sad;
    cout << cal - ca<< sad;
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