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
const long long N = 2e5+5;
long long chk[N];
void solve(){
    long long n , k;
    cin >> n >> k;
    set<long long>s;
    vector<long long>v(n);
    map<long long , long long>freq , mp;
    for(long long  i = 0; i < n; i++) {
        cin >> v[i];
    }
    long long ind = -1;
    for(long long i = 0 ; i < n ; i++){
        if(v[i] == v[n-1]) {
            ind = i;
            break;
        }
    }
    long long sum = 2;
    bool f= true , flag = true;
    long long cnt1 = 1, cnt2 = 1;
    for(long long i = 1, j = n-2; i < n and j >= 0;i++ , j--){
        if(v[i] == v[0]) cnt1++;
        if(v[j] == v[n-1]) cnt2++;
        if(cnt1 == k and cnt2 == k) {
            ha;
            return;
        }
    }
    na;
    
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