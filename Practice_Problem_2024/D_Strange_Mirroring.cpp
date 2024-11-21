 
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
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<int>stts, v;
    int n = s.size();
    while(q--)
    {
        int k;
        cin >> k;
        v.push_back(k);
        while(n <= k){
            stts.push_back(n);
            n *=2;
        }
        //cout << k << " "<< n << " "<< stts.size() << sad;
    }
    for(auto &k:v){
        bool orgnakifake = false;
        for(int i = stts.size()-1;i>= 0 ; i--){
            if(stts[i] < k){
                k-=stts[i];
                orgnakifake = !orgnakifake;
            }
        }
        char ans = s[k-1];
        //cout << ans <<sad;
        if(orgnakifake){
            if(isupper(ans)) {
                ans = tolower(ans);
            }
            else ans = toupper(ans);
        }
        cout << ans << " ";
    }
    cout << sad;
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