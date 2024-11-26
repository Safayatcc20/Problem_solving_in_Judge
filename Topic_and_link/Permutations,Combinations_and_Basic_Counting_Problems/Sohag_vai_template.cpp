#include<bits/stdc++.h>
using namespace std;
//recurrence nCk = (n-1)C(k) + (n-1)C(k-1)
//symmetry rule nCk = nC(n-k)
//nCr = summation of (0 to r) range ∑(n-1+j)C(j) here 0<=j <=r
//sum over k ∑(nCk) = 2^n where 0<=k <= n
// sum over n ∑(mCk)= (n+1)C(k+1) where k is fixed and 0<=m <= n
// sum over n and k  ∑(n+k)C(k)= (n+m+1)C(m) where 0<= k<= m
// sum of squars (nC0)^2 + (nC1)^2+...+(nCn)^2 = (2*n)C(n);
// weighted sum 0*(nC0)+ 1*(nC1)+2*(nC2)...+n(nCn)^2 = (2^(n-1))*(n);
// Fibonacci number (nC0) + (n-1)C1 + ...+(n-k)Ck+...+0Cn = F(n+1);


//carefull for constraint N
const int N = 5e6 + 9, mod = 1e9 + 7;
// Using Extended Euclidean Algorithm 
int f[N], inv[N], finv[N];
void prec() {
  f[0] = 1;
  for (int i = 1; i < N; i++) f[i] = 1LL * i * f[i - 1] % mod;
  inv[1] = 1;
  for (int i = 2; i < N; i++ ) {
    inv[i] = (-(1LL * mod / i) * inv[mod % i] ) % mod;
    inv[i] = (inv[i] + mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i < N; i++) finv[i] = 1LL * inv[i] * finv[i - 1] % mod;
}
int ncr(int n, int r) {
  if (n < r || n < 0 || r < 0) return 0;
  return 1LL * f[n] * finv[n - r] % mod * finv[r] % mod;
}
/* 
//using Fermat's theorem it's slower than extended euclidean Algorithm
//key shortcut ctrl + d u can select same name for this 
// remember mod depends on statement;
const long long mod = 1000000007; // 10^9

int bin_power(int a, int n ,int mod) {
  int ans = 1% mod;
  while(n){
    if(n & 1) ans = 1LL * ans * a % mod;
    a = 1LL * a * a % mod;
    n >>= 1;
  }
  return ans;
}
int inverse(int a, int p) {
  return bin_power(a, p - 2, p);
}
const long long MOD = 1000000007;
const int MAXN = 1000005;
const int MAXK = 101;

vector<long long> fact(MAXN , 1);        // Factorial array
vector<long long> inv_fact(MAXN , 1);    // Inverse factorial array


// Precompute factorials and their inverses modulo MOD
void precompute_factorials() {
    for (int i = 2; i <= MAXN ; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[MAXN ] = inverse(fact[MAXN ], MOD);  // Fermat's little theorem
    for (int i = MAXN -1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

// Compute C(n, k) % MOD using factorials and inverse factorials
long long binomial(long long n, long long k) {
    if (k < 0 || k > n) return 0;
    return (fact[n] * inv_fact[k] % MOD) * inv_fact[n - k] % MOD;
} */

// void brute() {
//  for (int i = 0; i < N; i++) {
//    C[i][0] = 1;
//  }
//  for (int i = 1; i < N; i++) {
//    for (int j = 1; j <= i; j++) {
//      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
//    }
//  }
// }

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();
  int q; cin >> q;
  while (q--) {
    int n, r; cin >> n >> r;
    cout << ncr(n, r) << '\n';
  }
  return 0;
}
// https://cses.fi/problemset/task/1079/