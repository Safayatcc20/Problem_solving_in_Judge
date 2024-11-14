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
using uint = unsigned int;

const int mx = 1e7 + 9;
const int mxprm = 6e6 + 9; 

int psz = 0; 

bitset <mx> mark; 
int primes[mxprm];
int mul[mxprm];  

void sieve() { 
    mark[0] = mark[1] = 1;
    primes[psz++] = 2;
    int lim = sqrt(mx * 1.0) + 2;
    for (int i = 4; i < mx; i += 2) mark[i] = 1;
    for (int i = 3; i < mx; i += 2) {
        if (!mark[i]) {
            primes[psz++] = i;
            if (i <= lim)
                for (int j = i * i; j < mx; j += i)
                    mark[j] = 1;
        }
    }
}

void solve(){
    long long n , k ;
    cin >> n >> k;
    vector<long long>v;
    if(n == 1){
        if(k == 1) cout << 1 << sad;
        else cout << -1 <<sad;
        return;
    }
    v.push_back(1);
    v.push_back(n);
    map<long long, long long>mp;
    for(long long i = 2; i * i<= n ; i++){
        if(n % i == 0 and mp[i] == 0){
            v.push_back(i);
            mp[i] = 1;
            if(i * i == n || mp[n/i]) continue;
            mp[n/i] = 1;
            v.push_back(n/i);
        }
    } 
    sort(all(v));
    if(v.size() < k){
        cout << -1 << sad;
    }
    else{
        cout << v[k-1] << sad;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    // long long t;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}