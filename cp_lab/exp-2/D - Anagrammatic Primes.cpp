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
const long long N = 1e6 + 10;
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
bool even(long long n ){
    while(n > 0){
        if(!((n % 10) & 1)){
            return true;
        }
        n /= 10;
    }
    return false;
}
bool isanagrammatic(long long n){
    vector<long long>v;
    while(n > 0){
        v.push_back(n % 10);
        n /= 10;
    }
    sort(all(v));
    sieve();
    n =  0;
    for(long long i = 0 ; i < v.size() ; i++){
        n = n *10 + v[i];
    }
    if(!isprime(n)){
        return false;
    }
    while(next_permutation(all(v))){
        n =  0;
        for(long long i = 0 ; i < v.size() ; i++){
            n = n *10 + v[i];
        }
        if(!isprime(n)){
            return false;
        }
    }
    return true;
}
// remember MOD depends on statement;
const long long MOD = 1000000000; // 10^9

long long power(long long x, long long n) {
    if (n == 0) {
        return 1;
    }
    long long y = power(x, n / 2);
    if (n % 2 == 0) {
        return (y * y) % MOD;
    } else {
        return (((y * y) % MOD) * x) % MOD;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    vector<long long>v;
    v.push_back(2);
    for(long long i = 3; i < 100000; i += 2){
        if(isprime(i)){
            if(even(i)){
                continue;
            }
            //cout << i << sad;
            if(isanagrammatic(i)){
                v.push_back(i);
            }
        }
    }
    //cout << sad;
    //cout << v.size() << sad;
    long long n ;
    while(cin >> n){
        if(n == 0){
            break;
        }
        bool f = true;
        long long range = log10(n)+1;
        long long chk = 1 ;
        while(range--){
            chk *= 10;
        }
        //cout << chk << sad;
        for(long long i = 0; i < v.size() ; i++){
            //cout << v[i] << " ";
            if(v[i] > n and v[i] < chk){
                cout << v[i] << sad;
                f = false;
                break;
            }
        }
        if(f){
            cout << 0 << sad;
        }
    }
}