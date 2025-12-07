/***** Bismillahir Rahmanir Rahim *****/
#include <bits/stdc++.h>
using namespace std;

static const int mod = 1000000007;

int addmod(int a, int b){ a += b; if(a >= mod) a -= mod; return a; }
int mulmod(long long a, long long b){ return int((a*b)%mod); }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<int> cnt(71, 0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        ++cnt[x];
    }
    vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
    int P = (int)primes.size();                 
    int m = 1 << P;                             

    vector<int> mask(71, 0);
    for(int v=1; v<=70; v++){
        int x = v, m = 0;
        for(int j=0;j<P;j++){
            int p = primes[j];
            int c = 0;
            while(x % p == 0){
                x /= p; c ^= 1;
            }
            if(c) m |= (1<<j);
        }
        mask[v] = m;
    }

    
    vector<int> pow(n+1, 1);
    for(int i=1;i<=n;i++) pow[i] = addmod(pow[i-1], pow[i-1]);

    vector<int> dp(m, 0), ndp(m, 0);
    dp[0] = 1;
    for(int v=1; v<=70; v++){
        if(cnt[v] == 0) continue;
        int evenWays = pow[cnt[v]-1];
        int oddWays  = pow[cnt[v]-1];
        int mv = mask[v];

        for(int i=0; i<m; i++){
            
            int waysEven = mulmod(dp[i], evenWays);
            int waysOdd  = mulmod(dp[i ^ mv], oddWays);
            ndp[i] = addmod(waysEven, waysOdd);
        }
        dp.swap(ndp);
        fill(ndp.begin(), ndp.end(), 0);
    }

    int ans = dp[0];
    ans = (ans - 1 + mod) % mod;
    cout << ans << '\n';
    return 0;
}
