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
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    cin >> t;
    vector<long long>p(10);;
    p[1] = 1;
    for(int i =2; i < 8; i++){
        p[i] = p[i-1]*10;
    }
    while (t--)
    {
        long long a , b , c , k;
        cin >> a >> b >> c >> k;
        bool f = false;
        long long aa , bb , cc, sum = 0;
        for(int i = p[a] ; i < p[a+1] ; i++){
            long long mn = p[c] - i , mx = p[c+1]-1 - i;
            mn = max(mn , p[b]) , mx = min(mx , p[b+1]-1);
            if(mx < mn) continue;
            long long l  = mx - mn + 1;
                //cout << mn << " "<< mx << sad;
            if(sum < k and sum >= k - l){
                f = true , aa = i , bb = mn + (k - sum-1);
                cc = aa + bb;
                //cout << aa << " " << bb << " "<< cc << sad;
            }
            sum += l;
            //cout << sum << sad;
        }
        if(f){
            cout << aa << " + " << bb << " = "<< cc << sad;
        }
        else minusone ;
    }
}