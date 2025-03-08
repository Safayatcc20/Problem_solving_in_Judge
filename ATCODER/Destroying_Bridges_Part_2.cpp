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
long long fact(long long n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
long long findXor(long long n)
{ // reming: function calling findXor(sending value - 1);
    long long rest = n % 4;
    if (rest == 0)
        return n;
    if (rest == 1)
        return 1;
    if (rest == 2)
        return n + 1;
    if (rest == 3)
        return 0;
}
// Linear Diophantine Equation ax + by = c;
// solution by using  Extended Euclidean algorithm one solution
int extgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool comp(pair<int , int>&a , pair<int , int>&b){
    return (a.first < b.first or a.first == b.first and a.second > b.second);
}
void solve()
{
    int n, c;
    cin >> n >> c;
    int sum = 0 ;
    vector<pair<int, int>> v(n) , vv(n-1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
        sum += v[i].first;
        if(i != 0){
            vv[i-1].first = v[i].first;
            vv[i-1].second = v[i].second;
        }
    }
    if((sum-v[0].first) * v[0].first <= c) {
        cout <<1 << sad;
        return;
    }
    sort(all(vv) ,  comp);
    int ans = 1;
    map<int , int>mp;
    mp[0] = 1;
    int k = 0 ;
    // for(auto &x:vv){
    //     cout << x.first << " " << x.second<<sad;
    // }
    while(ans < n){
        int sum = 0 ;   
        mp[vv[k].second] = 1;
        k++;
        // for(auto &x:mp){
        //     if(x.second == 1) cout << x.first << " ";
        // }
        // cout << sad;
        for(int i = 0 ; i < n ;i++){
            if(mp[i] == 0) continue;
                for(int j = 0 ;j < n ; j++){
                    if(mp[j] == 0) 
                    sum += v[i].first * v[j].first;
                }
            
        } 
        ans++;
        //cout << sum << sad;
        if(sum <= c){
            break;
        }
    }
    cout << ans << sad;
}
int32_t main()
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