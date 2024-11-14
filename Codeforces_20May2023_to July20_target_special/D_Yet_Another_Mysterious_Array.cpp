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
#define MAXN 100001
 
// stores smallest prime factor for every number
int spf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
 
    for (int i = 3; i * i < MAXN; i++) {
        // checking if i is prime
        if (spf[i] == i) {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j < MAXN; j += i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
map<int , int>mp;
void getFactorization(int x)
{
    vector<int> ret;
    while (x != 1) {
        int cnt = 0 , factor = spf[x];
        while(x %factor == 0 ) {
            cnt++ , x /= factor;
        }
        mp[factor] = max(mp[factor] , cnt);
    }
}
void solve(){
    int n ;
    cin >> n ;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    //cout << psz << sad;
    for(int i = 0 ; i < n ; i++){
        int take = v[i];
        getFactorization(take);
        /* while(take != 1){
            int cnt = 0 , factor = spf[take];
            while(take % factor == 0){
                cnt++;
                take /= factor;
            }
            mp[factor] = max(mp[factor] , cnt);
        } */
    }
    
    long long ans = 0;
    for(auto &x:mp){
        //cout << x.first << " " << x.second << sad;
        ans += x.second;
    }
    if(ans & 1) cout << "Alice" << sad;
    else cout << "Bob" << sad;
    mp.clear();
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