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
    sieve();
    long long n ;
    while(cin >> n){
        if(n == 0){
            break;
        }
        long long a = 2 , b = n-2;
        if(isprime(b)){
            cout << n << ":" << sad;
            cout << a << "+" << b << sad;
            continue;
        }
        bool f = true;
        for(long long i = 3; i < n ; i+=2){
            if(isprime(i) and isprime(n-i)){
                cout << n << ":" << sad;
                cout << a << "+" << b << sad;
                f = false;
                break;
            }
        }
        if(f){
            cout << n << ":" << sad;
            cout << "NO WAY!" << sad;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    long long n ;
    while(cin >> n){
        if(n == 0){
            break;
        }
        long long a = 2 , b = n-2;
        if(isprime(b)){
            cout << n << ":" << sad;
            cout << a << "+" << b << sad;
            continue;
        }
        bool f = true;
        for(long long i = 3; i < n ; i+=2){
            if(isprime(i) and isprime(n-i)){
                cout << n << ":" << sad;
                cout << i << "+" << n-i << sad;
                f = false;
                break;
            }
        }
        if(f){
            cout << n << ":" << sad;
            cout << "NO WAY!" << sad;
        }
    }
}