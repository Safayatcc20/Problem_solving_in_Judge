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
    if (!(x & 1))
        return false;
    return !prime[x];
}
void solve(){
    sieve();
    long long n;
    cin >> n;
    long long ans = 0;
    for(long long i = 1; i <= n ; i++){
        long long cnt = 0;
        //cout << "For" << i << " ";
        for(long long j = 2; j *  j <= i ; j++){
            if(i % j == 0){
                if(isprime(j)){
                    //cout << j << sad;
                    cnt++;
                }
                if(isprime(i / j) and j * j != i){
                    cnt++;
                    //cout << i / j << sad;
                }
            }
        }
        if(cnt == 2){
            ans++;
        }
    }
    cout << ans << sad;
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