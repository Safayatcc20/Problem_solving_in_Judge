
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
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
        string s;
        cin >> s;
        bool f = false;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            int num = s[i] - '0';
            for(int j = i + 1; j < n; j++){
                if(isprime(num*10 + s[j] - '0')){
                    cout << num *10 + s[j] - '0' << sad;
                    f = true;
                    break;
                }
            }
            if(f){
                break;
            }
        }
        if(f) continue;
        cout << -1 << sad;
    }
}