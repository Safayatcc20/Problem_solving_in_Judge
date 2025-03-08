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
        long long n , m;
        cin >> n >> m;
        map<long long , long long>mp;
        set<long long >s;
        vector<long long>v;
        for(long long i = n; i <= m ;i ++){
            if(isprime(i)){
                v.push_back(i);
            }
        }
        for(long long i = 1; i < v.size(); i++){
            mp[v[i]-v[i-1]]++;
            s.insert(v[i]-v[i-1]);
        }
        long long mx  = 0, ans = 0;
        for(auto &x:s){
            if(mp[x] > mx){
                mx = mp[x];
                ans = x;
            }
        }
        if(mx==0){
            cout << "No jumping champion" << sad;
            continue ;
        }
        long long cnt = 0;
        bool f = true;
        for(auto &x:s){
            if(mp[x] == mx){
                cnt++;
                if(cnt > 1){
                    cout << "No jumping champion" << sad;
                    f = false;
                    break;
                }
            }
        }
        
       if(f) cout << "The jumping champion is " << ans << sad;
        
    }
}