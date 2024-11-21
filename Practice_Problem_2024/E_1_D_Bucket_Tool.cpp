 
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
    int n , m;
    cin >> n >> m;
    vector<int>freq(n+1 , 0);
    for(int i = 0 ; i <= n ;i++) freq[i] = 1;
    set<pair<int , int>>s;
    for(int i = 0 ; i < n ; i++){
        s.insert({i , i});
    }
    s.insert({-1 , 1e18});
    s.insert({n, 1e18});
    for(int i = 0; i < m ; i++){
        int t;
        cin >> t;
        if(t == 1){
            int x , c;
            cin >> x >> c;
            x-- , c--;
            auto it = s.lower_bound({x , 1e18});
            auto it1 = *it;
            int cur = it1.first , curr = it1.second;
            --it;
            it1 = *it;
            int left = it1.first, leftc = it1.second;
            --it;
            it1 = *it;
            int right = it1.first, rightc = it1.second;
            freq[leftc]-= cur - left;
            freq[c]+= cur - left;
            it++;
            it = s.erase(it);
            if(c == curr) it = s.erase(it);
            if(c != rightc) s.insert({left, c});
        }
        else{
            int x;
            cin >> x;
            x--;
            cout << freq[x] << sad;
        }
    }
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