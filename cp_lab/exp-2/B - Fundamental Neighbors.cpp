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
    long long n;
    sieve();
    while(cin >> n){
        cout << n << " ";
        long long ans = 1;
        if(n % 2 == 0){
            long long two = 0 ;
            while(n % 2 == 0){
                n /= 2;
                two++;
            }
            ans = ans *(llround(pow(two , 2)));
        }
        for(long long i = 3; i * i <= n; i+= 2){
            long long cnt = 0 ;
            if(isprime(i)){
                while(n % i == 0){
                    cnt++;
                    n /= i;
                }
                if(cnt > 0) {
                    long long take = (llround(pow(cnt , i)));
                    //cout << " take = " << take << sad;
                    ans = ans * take;
                }
            }
        }
        cout << ans << sad;
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