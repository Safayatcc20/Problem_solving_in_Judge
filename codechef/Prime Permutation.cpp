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
const long long N = 1e7 + 10;
bool prime[N];
void sieve()
{
    prime[1] = prime[0] = true;
    for (long long i = 3; i * i <= N; i += 2)
    {
        if (prime[i])
        {
            continue;
        }
        for (long long j = i * i; j < N; j += i + i)
        {
            prime[j] = true;
        }
    }
}
bool isprime(long long x)
{
    if (x == 2)
        return true;
    else if ((x % 2 == 0))
        return false;
    return !prime[x];
}
void solve(){
    int n ;
    cin >> n;
    if(n < 4) {
        cout << -1 << sad;
        return;
    }
    int ans = n / 2 , a  = 0 , b = 0 ;
    if( isprime(n - 2)){
        a = 2 ;
        b = n - 2;
    }
    else{
        for(int i = 3; i  <= n /2; i+=2){
            if( isprime(i ) and isprime(abs(n - i) ) ){
                a = i  , b = n - i;
                break;
            }
        }
    }
    if( a==  0 and b == 0) {
        cout << - 1 << sad;
        return;
    }
    /* cout << ans << sad;
    cout << a << " "<< b << sad; */
    for(int i = 1; i <= ans ; i++){
        if(abs(max(a , b) + i) > n) {
            cout << abs(min(a , b) - i) << " ";
        }
        else cout << abs(max(a , b) + i) << " " ;
    }
    for(int i = ans+1; i <= n ; i++){
        if(abs(min(a , b) - i) > 0) {
            cout << abs(min(a , b) - i) << " ";
        }
        else cout << abs(max(a , b) + i) << " " ;
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
    sieve();
    while (t--)
    {
        solve();
    }
}