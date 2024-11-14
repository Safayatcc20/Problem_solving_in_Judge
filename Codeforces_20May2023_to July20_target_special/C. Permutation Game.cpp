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
    int n ;
    cin >> n;
    vector<int>v(n);
    map<int  , int>mp;
    for(int i = 0 ; i < n ; i++){
        cin >>v[i];
        mp[v[i]] = i;
    }
    vector<bool>vv(n+1);
    vv[1] = true;
    vv[n] = false;
    for(int i = n-1; i> 1; i--){
        int j = mp[i] + i;
        while(j < n){
            if(v[j] > i and vv[v[j]] == false){
                vv[i] = true;
                break;
            }
            j += i;
        }
        j = mp[i] - i;
        while(j >= 0){
            if(v[j] > i and vv[v[j]] == false){
                vv[i] = true;
                break;
            }
            j -= i;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(vv[v[i]]){
            cout << "A";
        }
        else cout << "B";
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
    //cin >> t;
    while (t--)
    {
        solve();
    }
}