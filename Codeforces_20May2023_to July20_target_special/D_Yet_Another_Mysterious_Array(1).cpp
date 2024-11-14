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

//storing the values in unsigned int
//since it prevents exceeding memory limit
//also, it automatically makes the numbers
//modulo 2^32

const int mx = 1e3 + 9; //max value of n
const int mxprm = 1e3 + 9; //max number of primes

int psz = 0; //keeping count the number of primes discovered

bitset <mx> mark; //to keep track of primes
int primes[mxprm]; //to store the primes
int mul[mxprm];  //to store the cumulative product of the primes

void sieve() { //just a prime sieve code
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
    int n ;
    cin >> n ;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    map<int , int>mp;
    //cout << psz << sad;
    for(int i = 0 ; i < n ; i++){
        int take = v[i];
        for(int j = 0 ; j < psz; j++){
            int cnt = 0;
            while(take % primes[j] == 0){
                take /= primes[j];
                cnt++;
            }
            mp[primes[j]]= max(mp[primes[j]] , cnt);
        }
        if(take > 1){
            mp[take] = max(mp[take] , 1);
        }
    }
    long long ans = 0;
    for(auto &x:mp){
        //cout << x.first << " " << x.second << sad;
        ans+=x.second;
    }
    if(ans & 1) cout << "Alice" << sad;
    else cout << "Bob" << sad;
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