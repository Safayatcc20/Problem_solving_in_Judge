 
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
int rangeSum(int l , int r){
    return query(r)- query(l-1);
}
/* 

using orderset
void solve(){
    int n;
    cin >> n;
    oset<pair<int , int>>o;
    vector<int> arr(n); // {value, index}
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];// 1-based index
    }
    vector<int>suffix(n),prefix(n);
    map<int , int>mp,smp;
    for(int i = n -1; i >= 0; i--){
        mp[arr[i]]++;
        suffix[i] = mp[arr[i]];
    }
    
    for(int i = 0 ; i< n-1 ;i++){
        smp[arr[i]]++;
        prefix[i] = smp[arr[i]];
    }
    int ans = 0 ;
    o.insert({suffix[n-1],n-1});
    for(int i = n -1; i >= 0; i--){
        
        int pre = prefix[i];
        //cout << pre << " "<<arr[i]<<" "<< suffix[i]<< " ";
        int o1 = o.order_of_key({pre, -1});
        ans+=o1;
        // cout << o1 <<" ";
        o.insert({suffix[i] , i});
        // cout << o.size() << sad;
    }
    cout << ans << sad;
} */
/* using BIT
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n); // {value, index}
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];// 1-based index
    }
    vector<int>suffix(n),prefix(n);
    map<int , int>mp,smp;
    for(int i = n -1; i >= 0; i--){
        mp[arr[i]]++;
        suffix[i] = mp[arr[i]];
    }
    
    for(int i = 0 ; i< n ;i++){
        smp[arr[i]]++;
        prefix[i] = smp[arr[i]];
    }
    int ans = 0 ;
    for(int i = n -1; i >= 0; i--){
        ans += query(prefix[i]-1);
        update(suffix[i] , 1 , n);
    }
    cout << ans << sad;
} */

#define mx 1000005 * 1LL
const int inf = 2000000000;
int ccnt[mx];
int trees[mx * 4 ];// space 4 * N neya hoi contest er somoy but 3 * N neya better 
void build(int node, int begin, int end) {
    if (begin == end) {
        trees[node] = ccnt[begin];
        return;
    }
    int left =  2 * node;
    int right =  2 * node + 1;
    int mid = (begin + end) / 2;
    build(left, begin, mid);
    build(right, mid + 1, end);
    trees[node] = (trees[left]+ trees[right]); // Update trees[node] with the min of left and right children
}

// segment trees query
// here i  and j is the starting and ending possition of given array or trees
// begin and end is the of range query
//  
// query and update O(log(n))
int query(int node , int begin , int end , int i , int j){
    if( i > end or j < begin){
        return 0;//No overlap 
    }
    if(begin >= i and end <= j){
        return trees[node] ; // Total overlap;
    }
    // Partial overlap
    // jodi 0 index e hoi left = node * 2 + 1 , right = node * 2 + 2 hobe;
    int left = node * 2;// 1 base indexing
    int right = node * 2 + 1;
    int mid = ( begin  + end) / 2;
    int x = query(left , begin, mid , i , j);
    int y = query(right ,  mid + 1,end , i , j);
    return x + y; // finding minimum range query
}
void update(int node , int begin , int end ,  int newvalue){
    
    if(begin == end ){
        trees[node]--; // update or set value 
        return ;
    }
    // Partial overlap

    int left = node * 2;// 1 base indexing
    int right = node * 2 + 1;
    int mid = ( begin  + end) / 2;
    if (newvalue <= mid) {
        update(left, begin, mid, newvalue);
    } 
    else {
        update(right, mid + 1, end, newvalue);
    }
    trees[node] = (trees[left] + trees[right]);
}

// using segment tree
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n); // {value, index}
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];// 1-based index
    }
    vector<int>suffix(n),prefix(n);
    map<int , int>mp,smp;
    for(int i = n -1; i >= 0; i--){
        mp[arr[i]]++;
        suffix[i] = mp[arr[i]];
    }
    
    for(int i = 0 ; i< n ;i++){
        smp[arr[i]]++;
        prefix[i] = smp[arr[i]];
    }
    for(int i = 0 ; i < n ;i++){
        ccnt[prefix[i]]++;
    }
    build(1 , 1, n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        update(1 , 1 , n, suffix[i]);
        ans += query(1 ,1 , n , 1 , prefix[i]-1);
        // cout << ans << " ";
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
    //cin >> t;
    while (t--)
    {
        solve();
    }
}