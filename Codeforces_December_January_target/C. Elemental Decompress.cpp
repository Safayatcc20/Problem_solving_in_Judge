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
void solve(){
    long long n ;
    cin >> n;
    vector<pair<long long  , long long>>v(n+1);
    vector<long long>a(n+1), b(n+1), p(n+1), q(n+1);
    long long mx = 0;
    set<long long > sa , sb;
    map<long long , long long>mp;
    for(long long i = 1; i <= n ; i++){
        cin >> v[i].first;
        v[i].second = i;
        sa.insert(i);
        sb.insert(i);
        p[i] = q[i] = 0 ;
    }
    sort(all(v));
    for(long long i = 1 ; i <= n ; i++){
        if(sa.find(v[i].first) != sa.end()){
            p[i] = v[i].first;
            sa.erase(v[i].first);
        }
        else if(sb.find(v[i].first) != sb.end()){
            q[i] = v[i].first;
            sb.erase(v[i].first);
        }
        else{
            na;
            return;
        }
    }
    for(long long i = 1; i <= n ; i++){
        if(p[i] == 0){
            p[i] = *sa.begin();
            sa.erase(sa.begin());
        }
        if(q[i] == 0){
            q[i] = *sb.begin();
            sb.erase(sb.begin());
        }
        if(max(p[i] , q[i]) != v[i].first){
            na;
            return;
        }
        a[v[i].second] = p[i] ;
        b[v[i].second] = q[i] ;
    }
    ha;
    for(long long i = 1; i <= n ; i++){
        cout << a[i] << " ";
    }
    cout <<sad;
    for(long long i = 1; i <= n ; i++){
        cout << b[i] << " ";
    }
    cout <<sad;
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