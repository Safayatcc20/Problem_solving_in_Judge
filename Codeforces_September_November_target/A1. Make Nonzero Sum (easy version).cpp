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
void solve(){
    long long n ;
    cin >> n ;
    vector<long long>v(n);
    set<long long>s;
    for(auto &x:v) {
        cin >> x;
        s.insert(x);
    }
    if(n & 1){
        cout << -1 << sad;
        return ;
    }
    if(s.size() ==1 ){
        cout << 1 << sad;
        cout << 1 << " " << n << sad;
        return;
    }
    long long k = 0 ;
    vector<pair<long long , long long>>vv;
    for(long long i = 0 ; i < n ;){
        if(v[i] == v[i+1]){
            k++;
            vv.push_back({i+1, i+2});
            i+=2;
        }
        else if(v[i] != v[i+1]){
            k+=2;
            vv.push_back({i+1,i+1});
            vv.push_back({i+2,i+2});
            i+=2;
        }
    }
    cout << k << sad;
    for(auto &x:vv){
        if(x.second == 0){
            cout << x.first << sad;
        }
        else{
            cout << x.first << " " << x.second << sad;
        }
    }
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}