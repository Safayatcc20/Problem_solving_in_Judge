 
 /***** Bismillahir Rahmanir Rahim *****/
 
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using oset = tree<T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define int long long
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
    string s;
    cin >> s;
    int ans = 0 ;
    vector<int>ind;
    int cnt = 0, j = n;
    for(int i = 0; i < n ;){
        bool f = false;
        while(i < n and s[i] =='1'){
            f =true;
            i++;
        }
        if(f) ans++;
        else i++;
        //cout << ans << " " << i << sad;
        if(ans == k-1){
            ind.push_back(i);
        }
        if(ans == k){
            j = i-1;
            while(j >= 0 and s[j] == '1'){
                cnt++;
                j--;
            }
            j = i;
            break;
        }
    }
    //cout << j << " "<< cnt << sad;
    string res;
    for(int i = 0 ; i < ind[0]; i++){
        res += s[i];
    }
    while(cnt--){
        res+='1';
    }
    for(int i =ind[0]; i < n; i++){
        if(s[i] == '1') break;
        res += s[i];
    }
    //cout << res << sad;
    while(j < n){
        res+=s[j];
        j++;
    }
    cout << res << sad;
}
int32_t main()
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