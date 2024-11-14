/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.rbegin(), b.rend()
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
    int n , k;
    cin >> n >> k;
    vector<int>v(n);
    map<int , int>mp ,ft , lt;
    for(auto  &x:v) {
        cin >> x;
        mp[x] = 1;
    }
    for(int i = 0 ; i< n ;i++){
        if(ft.find(v[i]) == ft.end()) ft[v[i]] =  i;
    }
    for(int i = n - 1; i>= 0 ; i--){
        if(lt.find(v[i]) == lt.end()) lt[v[i]] =  i;
    }
    sort(all(v));
    for(int i = 0 ; i < n - 1; i++){
        if(ft[v[i]] <= ft[v[i+1]]) ft[v[i+1]] = ft[v[i]];
        if(lt[v[i+1]] <= lt[v[i]]) lt[v[i+1]] = lt[v[i]];
    }
    vector<int>ans;
    for(int i = 1; i <= k ; i++){
        if(mp[i]){
            //cout << lt[i] << " "<< ft[i] << sad;
            ans.push_back((lt[i] - ft[i]+1) * 2);
        }
        else{
            ans.push_back(0);
        }
    }
    for(auto &x:ans){
        cout << x << " " ;
    }
    cout << sad;
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