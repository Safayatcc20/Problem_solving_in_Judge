 
 /***** Bismillahir Rahmanir Rahim *****/
 
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using oset = tree<T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/// order_of_key(x) returns number of elements strictly less than x
/// find_by_order(x) return x th element of the set (0 based index)
///less dile choto theke boro sajano
///less equal dile multiset er moto kaj kore
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
#define int long long
long long t = 1;
const int MAXN = 2e6;
//Video
//https://www.youtube.com/watch?v=DPiY9wFxGIw&list=PLauivoElc3gilwo3g_ASRqysDvybOlzVQ&index=2
// BIT(Fenwick Tree) for range counting
// There is a trick when we need to use inversion concept 
// we use the value as a Index at this time if the value is
// a[i] = 1e9 we set value equal to  1e4 = 1 , 1e8 = 2 , 1e9 = 4 like this way
// reason is total array size never 10^5 
// map<int , int>mp; mp[1e4] =  1, mp[1e8] = 2 ,mp[1e9]  = 3
int BIT[MAXN];

// Update BIT at index idx
// Here we are updating by adding the value of index i
// also including range such as 
// 13 is include 14, 16 
void update(int idx, int value, int n) {
    while (idx <= n) {
        BIT[idx] += value;
        idx += idx & -idx;
        // here we update also the including part of idx
        // 1101(13){13-13} -> 1101+0001 = 1110(14){13-14} -> 1110+0010= 10000(16){1-16} so on
        //{i - j} define which range capture here
    }
}

// Query BIT for sum of (1 to i'th) index
int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= idx & -idx;
        // here we cover the index from 1 to i
        // 1101(13){13-13} -> 1101 -( 1101 & 0001) = 1100(12){13-14} 
        // 1100(12){9-12} -> 1100- (1100 & 0100)= 1000(8){1-8} 
        // 1000(8){1-8} -> 1000 - (1000 & 1000)= 0000(0) 
    }
    return sum;
}
//Range Update and Point Query
void range_add(int l, int r, int val, int n) {
    update(l, val , n);
    update(r + 1, -val, n);
}
int rangeSum(int l , int r){
    return query(r)- query(l-1);
}
void solve(){
    int n , m;
    cin >> n >> m;
    vector<int>v(n+5);
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        v[x] = i;
    }
    
    vector<vector<int>>divisor(n+5);
    vector<vector<pair<int , int>>>queries(n+5);
    for(int i = 1; i <= n ;i++){
        for(int j= i; j <= n ; j+=i){
            if (v[i] > v[j]) {
                divisor[v[i]].emplace_back(v[j]);
            } 
            else {
                divisor[v[j]].emplace_back(v[i]);
            }
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(auto &x:divisor[i]){
    //         cout << x << ' ';
    //     }
    //     cout << sad;
    // }
    for(int i = 0 ; i < m ;i++){
        int l , r;
        cin >> l >> r;
        queries[r].push_back({l , i});
    }
    vector<int>ans(m);
    for(int i = 1; i<= n ;i++){
        for(int j = 0 ; j < divisor[i].size();j++){
            update(divisor[i][j], 1 , MAXN);
        }
        for(int j = 0 ; j < queries[i].size();j++){
            ans[queries[i][j].second] = query(i)  - query(queries[i][j].first-1);
        }
    }
    for(auto &x:ans){
        cout << x << " ";
        cout << sad;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
 //   cin >> t;
    while (t--)
    {
        solve();
    }
}