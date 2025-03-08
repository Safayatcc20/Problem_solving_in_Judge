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
    prime[0] = true;
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
    sieve();
    long long n , c;
    while(cin >> n >> c){
        vector<long long>v;
        for(long long i = 1; i <= n; i++){
            if(isprime(i)){
                v.push_back(i);
            }
        }
        //cout << v.size() << sad;
        cout << n << " " << c << ": ";
        if(v.size() <= 2 * c){
            cout << v[0];
            for(long long i = 1; i < v.size() ; i++){
                cout << " " << v[i];
            }
            cout << sad;
        }
        else if(v.size() & 1){
            long long nn = v.size()/ 2;
            cout << v[nn - c + 1];
            for(long long i = nn - c + 2; i <= v.size()/2 ; i++){
                cout << " " << v[i] ;
            }
            c--;
            for(long long i = nn + 1; c ; i++){
                cout << " " << v[i] ;
                c--;
            }
            cout << sad; 
        }
        else{
            long long nn = v.size()/ 2;
            cout << v[nn-c];
            for(long long i = nn - c + 1; i <= v.size()/2 ; i++){
                cout << " " << v[i] ;
            }
            c--;
            for(long long i = nn + 1; c ; i++){
                cout << " " << v[i] ;
                c--;
            }
            cout << sad ;
        }
        cout << sad;
    }
}