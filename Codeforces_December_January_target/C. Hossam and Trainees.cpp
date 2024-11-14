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
constexpr bool multiple_test_cases = 1;
long long gcd(long long x, long long y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
long long lcm(long long x, long long y)
{
    return ((x * y) / gcd(x, y));
}
const long long N = 100000;
bool prime[N+1];
vector<long long>primelist;
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
void sieve()
{
    prime[1] = prime[0] = true;
    prime[2] = false;
    for(long long i = 4; i <= N ; i+=2){
        prime[i] = true;
    }
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
    primelist.push_back(2);
    for(long long i = 3; i <= N; i++){
        if(!prime[i]){
            primelist.push_back(i);
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

    long long n, cnt = 0  ;
    cin >>n;
    vector<long long>v;
    for(long long i = 0; i < n  ;i++) {
        long long x;
        cin >> x;
            v.push_back(x);
    }
    //if(cnt == n){
       // na;
    //}
    map<long long  , long long>mp;
    for(long long i = 0 ; i < n ; i++){
        long long take = v[i];
        for(long long j =  0; primelist[j]*primelist[j] <= take; j++){
            if(v[i] % primelist[j] == 0)
            {
                mp[primelist[j]]++;
                while(take % primelist[j] == 0){
                    take /= primelist[j];
                }
            }
        }
        if(take != 1){
            mp[take]++;
        }
    }
    for(auto &x:mp){
        if(x.second > 1){
            ha;
            return;
        }
    }
    na;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    sieve();
    cin >> t;
    while (t--)
    {
        long long n, cnt = 0  ;
        cin >>n;
        vector<long long>v;
        for(long long i = 0; i < n  ;i++) {
            long long x;
            cin >> x;
                v.push_back(x);
        }
        //if(cnt == n){
        // na;
        //}
        map<long long  , long long>mp;
        for(long long i = 0 ; i < n ; i++){
            long long take = v[i];
            for(long long j =  0; primelist[j]*primelist[j] <= take; j++){
                if(v[i] % primelist[j] == 0)
                {
                    mp[primelist[j]]++;
                    while(take % primelist[j] == 0){
                        take /= primelist[j];
                    }
                }
            }
            if(take != 1){
                mp[take]++;
            }
        }
        bool flag = false;
        for(auto &x:mp){
            if(x.second > 1){
                flag = true;
                break;
            }
        }
        if(flag) ha;
        else na;
    }
}