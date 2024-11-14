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
    sieve();
    long long n ;
    cin >> n;
    if(n == 1){
        cout << 1 << sad;
        cout << 1 << sad;
        return;
    }
    if(n == 2){
        cout << 1 << sad;
        cout << 1 << " "<< 1 << sad;
        return;
    }
    vector<long long>v(n), ans;
    for(int i = 0 ; i < n ; i++){
        v[i] = i+2;
    }
    cout << 2 << sad;
    for(auto &x:v){
        if(isprime(x)){
            cout << 1<<  " ";
        }
        else{
            cout << 2 <<  " ";
        }
        //cout << x << sad;
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