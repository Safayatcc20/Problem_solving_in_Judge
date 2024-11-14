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
    long long wrong = 0;
    for(auto &x:v) {
        cin >> x;
        wrong +=abs(x);
    }
    long long chk = 0 , chker = 0;
    if(wrong == 0){
        cout << 1 << sad;
        cout << 1 << " " << n << sad;
        return ;
    }
    if(wrong & 1){
        cout << -1 << sad;
        return;
    }
    long long k = 0 ;
    vector<pair<long long , long long>>vv;
    long long i = 0;
    while(i < n ){
        if(v[i] == 1 and v[i+1] == 1){
            vv.push_back({i + 1 , i+2});
            i+= 2;
        }
        else if(v[i] == -1 and v[i+1] == -1){
            vv.push_back({i + 1 , i+2});
            i+= 2;
        }
        else if(v[i] == -1 and v[i+1] == 1){
            vv.push_back({i + 1 , i+1});
            vv.push_back({i + 2 , i+2});
            i+= 2;
        }
        else if(v[i] == 1 and v[i+1] == -1){
            vv.push_back({i + 1 , i+1});
            vv.push_back({i + 2 , i+2});
            i+= 2;
        }
        else if(v[i] == 1 and v[i+1] == 0 and chk != 1){
            chk = 1;
            vv.push_back({i + 1 , i+1});
            i+= 1;
        }
        else if(v[i] == 0 and v[i+1] == 1 and chk == 1){
            chk = 0;
            vv.push_back({i + 1 , i+2});
            i+= 2;
        }
        else if(v[i] == -1 and v[i+1] == 0 and chker != 1){
            chker = 1;
            vv.push_back({i + 1 , i+1});
            i+= 1;
        }
        else if(v[i] == 0 and v[i+1] == -1 and chker == 1){
            chker= 0;
            vv.push_back({i + 1 , i+2});
            i+= 2;
        }
        else if(v[i] == 0){
            vv.push_back({i+1, i+1});
            i++;
        }
    }
    cout << vv.size() << sad;
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