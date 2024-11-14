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
    for(int j = 1; j<= t; j++)
    {
        cout << "Case " << j << ": " ;
        int n;
        cin >> n;
        if(n-2 >= 0 and isprime(n-2)){
                //cout <<2 << " " << n-2 << sad;
            ha;
            continue;
        }
        bool f = false;
        for(int i = 3; i< n-1; i+=2){
            if(isprime(i) and isprime(n-i)){
                ha;
                f = true;
                break;
            }
        }
        if(!f){
            na;
        }
    }
}