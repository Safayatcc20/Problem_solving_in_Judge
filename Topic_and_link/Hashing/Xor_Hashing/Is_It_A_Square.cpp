 
 /***** Bismillahir Rahmanir Rahim *****/

#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using oset = tree<T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/// order_of_key(x) returns number of elements strictly less than x
/// find_by_order(x) return x th element of the set (0 based index)
///less dile choto theke boro sajano
///less equal dile multiset er moto kaj kore
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
#define int long long
long long t = 1;
constexpr bool multiple_test_cases = 1;


long long rng() {
	static std::mt19937 gen(
	    std::chrono::steady_clock::now().time_since_epoch().count());
	return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}
#define MAXN 1000005 // Carefull when solving the problem
 
// stores smallest prime factor for every number
int spf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
vector<int>primes;
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
    for(int i = 2; i < MAXN; i++){
        if(spf[i] == i) primes.push_back(i);
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
void solve(){
    int n  , q;
    cin >> n >> q;
    map<int , int>hash;
    vector<int>a(n) , b(n);
    for(auto &x:a){
        cin >> x;
        
    }

    for(int i = 0; i < primes.size(); i++){
        // cout << primes[i] << " ";
        hash[primes[i]] = rng();
    }
    
    vector<int>xora(n+1);
    vector<int>xorzero(n+1);
    vector<int>xorneg(n+1);
    set<int>s;
    hash[0] = rng();
    xora[0] = hash[0];
    xorzero[0] = 0;
    xorneg[0] = 0;

    for(int i = 0 ; i< n; i++){
        int chk = 0;
        int val = abs(a[i]);
        if(val == 0){
            xorzero[i+1] = xorzero[i] + 1;
        }
        else{
            xorzero[i+1] = xorzero[i] ;
        }
        if(a[i]< 0){
            xorneg[i+1] = xorneg[i] + 1;
        }
        else{
            xorneg[i+1] = xorneg[i] ;
        }
        while(val > 1){
            int cnt = 0;
            int x = spf[val];
            while(val % x== 0){
                cnt^= 1;
                val /= x;
            }
            if(cnt) chk ^= hash[x];
        }
        if(val > 1) chk ^= hash[val];
        xora[i+1] = xora[i] ^ chk;
    }
    

    for(int i = 0 ;i < q; i++){
        int x, y;
        cin >> x >> y;
        int l = xorzero[x-1];
        int r = xorzero[y];
        int cal = ( r - l);
        int ll = xorneg[x-1];
        int rr = xorneg[y];
        int calc = ( rr - ll);
        
        if(cal >0){
            cout << "Yes"<< sad;
        }
        else if((xora[x-1] ^ xora[y]) == 0 and !(calc & 1)) {
            cout <<"Yes"<< sad;
        }
        else cout << "No"<< sad;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    // cin >> t;
    sieve();
    while (t--)
    {
        solve();
    }
}