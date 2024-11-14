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
    int n , m;
    cin >> n >> m;
    string s;
    cin >> s;
    int z = -1, o = n+1;
    vector<long long>id1(n), id0(n);
    set<pair<long long , long long>>st;
    for(long long i = 0 ; i < n ;i++){
        if(s[i]  == '0'){
            z = i;
            id0[i] = z;
        }
        else{
            id0[i] = z;
        }
    }
    for(long long i = n-1; i >= 0;i--){
        if(s[i]  == '1'){
            o = i;
            id1[i] = o;
        }
        else{
            id1[i] = o;
        }
    }
    for(long long i = 0; i <m ; i++){
        int  l , r;
        cin >> l >> r;
        l-- , r--;
        l = id1[l];
        r = id0[r];
        if(l >= r){
            l = -1, r = -1;
        }
        //cout << l << " " << r << sad;
        st.insert({l , r});
    }
    cout << st.size() << sad;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}