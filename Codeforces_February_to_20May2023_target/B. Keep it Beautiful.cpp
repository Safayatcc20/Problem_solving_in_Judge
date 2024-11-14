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
    vector<long long>v(n), ans(n);
    for(auto &x:v) cin >> x;
    long long mn = v[0] , last;
    ans[0] = 1;
    bool flag = true;
    map<int , int>mp;
    cout << 1 ;
    for(int i = 1; i < n ; i++){
        if(mn <= v[i] ){
            ans[i] = 1;
            mn = v[i];
            cout << 1 ;
        }
        else if(v[0] < v[i]){
            ans[i] = 0;
            cout << 0;
        }
        else if(flag){
            int j = i+1;
            mn = v[i];
            ans[i] = 1;
            cout << 1 ;
            last = mn;
            while(j < n){
                if(mn <= v[j] and v[j] <= v[0]){
            //cout << v[j] << sad;
                    
                    if(v[j] >= v[j-1] and last <= v[j]){
                        ans[j] = 1;
                        mp[j] = 1;
                        last = v[j];
                    cout << ans[j] ;
                    }
                    else if(ans[j-1] == 0 and last <= v[j]){
                        cout << 1 ;
                        ans[j] = 1;
                        last = v[j];
                    }
                    else{
                        ans[j] = 0;
                    cout << ans[j];
                    }
                }
                else{
                    ans[j] = 0;
                    cout << ans[j] ;
                }
                j++;
            }
            //cout << j << sad;
            i = j;
        }
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