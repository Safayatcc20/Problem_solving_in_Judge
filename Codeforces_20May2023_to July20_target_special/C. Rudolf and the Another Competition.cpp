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
bool comp(pair<long long , pair<long long , long long>>&a , pair<long long , pair<long long, long long>>&b){
    return (a.first > b.first || (a.first == b.first and (a.second.second < b.second.second || (a.second.second == b.second.second and a.second.first < b.second.first))));
}
void solve(){
    int n , m , h;
    cin >> n >> m >> h;
    vector<vector<long long>>v;
    for(int i =0 ; i < n ; i++){
        vector<long long>vv(m);
        for(int j = 0 ; j < m ; j++){
            cin >> vv[j];
        }
        v.push_back(vv);
    }
    vector<pair<long long , pair<long long , long long>>>rank;
    for(int i = 0 ; i < n ;i++){
        sort(v[i].begin() , v[i].end());
        long long sum = 0, minute = 0 , cnt = 0, pre = 0;
        for(int j = 0 ; j < m ; j++){
            if(minute + v[i][j] <= h){
                //pre = sum;
                sum += (minute + v[i][j]);
                minute += v[i][j];
                cnt++;
            }
        }
        rank.push_back({cnt, {i , sum} });
    }
    sort(all(rank) , comp);
    //reverse(all(rank));
    for(int i = 0; i < n ; i++){
        
    //cout << rank[i].first << " " << rank[i].second.first << " " << rank[i].second.second << sad;
        if(rank[i].second.first == 0){
            cout << i+1 << sad;
            return;
        }
    }
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