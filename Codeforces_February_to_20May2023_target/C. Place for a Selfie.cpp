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
    long long n , m ;
    cin >> n >> m ;
    vector<long long>v(n);
    for(auto &x:v) cin >> x;
    sort(all(v));
    for(long long i = 0 ; i < m ; i++){
        long long a , b , c;
        cin >> a >> b >> c;
        double chk1 = b - 2 * sqrtl(a * c);
        double chk2 = b + 2 * sqrtl(a * c) ;
        long long test = 0;
        long long l  =  0  ,  r = n;
        bool f = true;
        long long ind = lower_bound(all(v) , b) - v.begin();
        //cout << ind << sad;
        if((b - v[ind]) *  (b - v[ind]) < 4 * a * c and ind < n){
            ha;
            cout << v[ind] << sad;
            f = false;
        }
        else if((b - v[ind-1]) *  (b - v[ind-1]) < 4 * a * c and ind > 0){
            ha;
            cout << v[ind-1] << sad;
            f = false;
        }
        else na;
    }
    cout << sad;
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