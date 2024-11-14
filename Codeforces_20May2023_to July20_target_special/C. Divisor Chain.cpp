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
    int n;
    cin >> n;
    vector<int>v;
    map<int , int>mp;
    v.push_back(n);
    int track = 0 ;
    while(n != 1){
        if(isprime(n) and mp[1] <= 2){
            mp[1]++;
            v.push_back(n-1);
            n--;
            if( n == 6 and mp[1]){
                v.push_back(4);
                v.push_back(2);
                v.push_back(1);
                n = 1;
            }
            continue;
        }
        if(n % 2 == 0 and mp[n / 2] <= 2){
            mp[n / 2]++;
            v.push_back(n / 2);
            n = n - n / 2;
            if(n == 5 and mp[1]){
                v.pop_back();
                v.push_back(2);
                n *= 2;
                n -= 2;
            }
            continue;
        }
        bool f = true;
        for(int i = 3; i * i<= (n) ; i+= 2){
            if(isprime(i) and mp[n / i] <=2 and n %  i == 0){
                mp[n / i]++;
                v.push_back(n- n /i);
                n = n - n / i;
                track = i;
                f = false;
                break;
            }
        }
        if(f){
            
        }
    }
    cout << v.size() << sad;
    for(auto &x:v){
        cout << x <<  " ";
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
    sieve();
    cin >> t;
    while (t--)
    {
        solve();
    }
}