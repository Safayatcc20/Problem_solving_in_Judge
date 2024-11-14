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
const long long N = 10000;
long long prime[N];
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
void solve(){
    vector<long long>store(1e7);
    for(int i = 1; i < 1e7; i++){
        if(i < 10){
            store[i] = i;
        }
        else{
            int take = i , product = 1;
            while(take > 0){
                if(take % 10 != 0){
                    product *= (take % 10);
                }
                take /= 10;
            }
            store[i] = store[product];
        }
    }
    vector<vector<long long>>pre(10,vector<long long>(1e7));
    for(int i = 1; i < 10 ; i++){
        for(int j = 1; j < 1e7; j++){
            if(store[j] == i)
            pre[i][j] += pre[i][j-1]+1;
            else
            pre[i][j] += pre[i][j-1];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l , r , k;
        cin >> l >> r >> k;
        cout << pre[k][r] - pre[k][l-1] << sad; 
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}