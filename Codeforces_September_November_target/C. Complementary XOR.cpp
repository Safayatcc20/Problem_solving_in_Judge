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
    long long n;
    cin >> n;
    string a , b , c, d;
    cin >> a >> b;
    c = a  ,  d = b;
    long long l = -1 , r = -1 , one = 0 , zero  = 0;
    for(long long i = 0; i < n ; i++){
        if(a[i] == b[i]){
            one++;
        }
        else{
            zero++;
        }
    }
    if(one & 1 and  zero & 1){
        na;
        return;
    }
    vector<pair<long long , long long>>v;
    long long k = 0 , ind = -1 , par = 0;
    for(long long i = 0; i < n ; i++){
        if(a[i] == '1'){
            ind = i;
            break;
        }
    }
    for(long long i = ind; i < n ; i++){
        if(a[i] == '1' and l == -1){
            l = i+1;
        }
        else if(a[i] == '1'){
            r = i+1;
        }
        else{
            k++;
            if(r == -1){
                v.push_back({l , l});
            }
            else{
                par++;
                v.push_back({l , r});
            }
            l = -1;
            r = -1;
        }
    }
    ha;
    if(par){
        cout << 3 << sad;
        cout << 1 << " " << n << sad;
        cout << ind+1 << n << sad;
        cout << 1 << " " << sad;
    }
    if(k == 0){
        cout << n << sad;
        for(long long i = 0 ; i < n ;i++){
            cout << i + 1 << " " << i+1 << sad;
        }        
        return;
    }
    cout << k << sad;
    for(auto x : v){
        cout << x.first << " " << x.second << sad;
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