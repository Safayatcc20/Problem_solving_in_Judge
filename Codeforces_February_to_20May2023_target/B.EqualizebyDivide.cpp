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
bool equ(vector<long long>v){
    set<long long>s;
    for(long long i = 0 ; i < v.size();i++){
        s.insert(v[i]);
    }
    if(s.size() == 1){
        return false;
    }
    else{
        return true;
    }
}
void solve(){
    long long n;
    cin >> n;
    set<long long>s;
    vector<long long>v(n), cop(n);
    for(auto &x:v) {cin >> x;
    s.insert(x);
    cop = v;
    }
    if(s.size() == 1){
        cout << 0 << sad;
        return;
    }
    long long cnt = 0 ;
    vector<pair<long long , long long>>ans;
    while(equ(v)){
        long long mn = INT_MAX;
        long long ind = -1;
        for(long long i = 0 ; i < n ; i++){
            if(v[i] <= mn){
                mn = v[i];
                ind = i;
            }
        }
        for(long long i = 0; i < n ;i++){
            if(v[i] > mn){
                if(v[i] % mn){
                    ans.push_back({i , ind});
                    v[i] = v[i] / mn+1;
                }
                else{
                    ans.push_back({i , ind});
                    v[i] = v[i] / mn;
                }
            }
        }
        if(cop == v){
            cout << -1 << sad;
            return;
        }
        cop = v;
    }
    //for(long long i = 0 ; i <n ; i++){
      //  cout << v[i] << " " ;
    //}
    //cout << sad;
    cout << ans.size() << sad;
    for(long long i = 0 ; i < ans.size() ; i++){
        cout << ans[i].first+1 << " " << ans[i].second+1 << sad;
    }
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