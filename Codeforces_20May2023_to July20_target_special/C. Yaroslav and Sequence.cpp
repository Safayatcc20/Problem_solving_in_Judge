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
    int n;
    cin >> n;
    bool f = true;
    vector<int>v(2 * n-1);
    for(auto &x:v) {
        cin >> x;
        if(x < 0 ) f = false;
    }
    long long ans  =  INT_MIN , sum = 0 ;
    if(f){

        for(auto &x:v) sum += x;
        cout << sum << sad;
        return;
    }
    sort(all(v));
    for(long long i = 0 ; i < n ; i++){
        int j = i;
        int cnt = 0;
        if(i - 1 >= 0){
            sum+= v[i-1];
        }
        int add = 0 ;
        while(cnt < n){
            cnt++;
            add += (-v[j]);
            j++;
        }
        i = j-2;
        //cout << sum <<  " " << add << " " ;
        if(cnt == n){
            for(int k = j; k < 2* n - 1; k++){
                add += v[k];
            }
        }
        cout << sad;
        //for(auto &x:v) cout << x << " "; cout << sad;
        ans = max(ans , sum + add);
        //cout << add << " " << ans << sad;
    }
    cout << ans << sad;
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