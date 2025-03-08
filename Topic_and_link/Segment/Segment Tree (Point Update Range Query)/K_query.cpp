/* #include <bits/stdc++.h>
using namespace std;

const int MAXN = 30001;

// BIT for range counting
int BIT[MAXN];

// Update BIT at index idx
void update(int idx, int value, int n) {
    while (idx <= n) {
        BIT[idx] += value;
        idx += idx & -idx;
    }
}

// Query BIT for prefix sum up to index idx
int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n); // {value, index}
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i + 1; // 1-based index
    }

    int q;
    cin >> q;

    vector<tuple<int, int, int, int>> queries(q); // {k, i, j, query_id}
    vector<int> results(q);

    // Read queries
    for (int idx = 0; idx < q; ++idx) {
        int i, j, k;
        cin >> i >> j >> k;
        queries[idx] = {k, i, j, idx};
    }

    // Sort the array by value in descending order
    sort(arr.rbegin(), arr.rend());

    // Sort the queries by k in descending order
    sort(queries.rbegin(), queries.rend());

    int arrIdx = 0;
    for (int qIdx = 0; qIdx < q; ++qIdx) {
        int k = std::get<0>(queries[qIdx]);
        int i = std::get<1>(queries[qIdx]);
        int j = std::get<2>(queries[qIdx]);
        int query_id = std::get<3>(queries[qIdx]);

        // Process all elements in the array greater than k
        while (arrIdx < n && arr[arrIdx].first > k) {
            update(arr[arrIdx].second, 1, n); // Mark this element in the BIT
            arrIdx++;
        }

        // Answer the query using the BIT
        results[query_id] = query(j) - query(i - 1);
    }

    // Output results
    for (int res : results) {
        cout << res << "\n";
    }

    return 0;
} */

#include<bits/stdc++.h>
using namespace std;
#define mx 30005 * 1LL
const int inf = 2000000000;
int arr[mx];
vector<vector<int>> tree(4*mx);// space 4 * N neya hoi contest er somoy but 3 * N neya better 
void build(int node, int begin, int end) {
    if (begin == end) {
        tree[node].push_back(arr[begin]);
        return;
    }
    int left =  2 * node;
    int right =  2 * node + 1;
    int mid = (begin + end) / 2;
    build(left, begin, mid);
    build(right, mid + 1, end);
    tree[node].resize(tree[left].size() + tree[right].size());
    // Update tree[node] with the min of left and right children
    merge(tree[left].begin(), tree[left].end(),
          tree[right].begin(), tree[right].end(),
          back_inserter(tree[node]));
}

// segment tree query
// here i  and j is the starting and ending possition of given array or tree
// begin and end is the of range query
//  
// query and update O(log(n))
int query(int node , int begin , int end , int l , int r , int val){
    if( l > end or r < begin){
        return 0;//No overlap 
    }
    if(begin >= l and end <= r){
        int ans = tree[node].end() - upper_bound(tree[node].begin() , tree[node].end() , val);
        return ans; // Total overlap;
    }
    // Partial overlap
    // rodi 0 index e hoi left = node * 2 + 1 , right = node * 2 + 2 hobe;
    int left = node * 2;// 1 base indexing
    int right = node * 2 + 1;
    int mid = ( begin  + end) / 2;
    int x = query(left , begin, mid , l , r , val);
    int y = query(right ,  mid + 1,end , l , r , val);
    return x + y;
}
// void update(int node , int begin , int end , int i , int newvalue){
//     if( i > end or i < begin){
//         return ;//No overlap 
//     }
//     if(begin >= i and end <= i){
//         tree[node].push_back(newvalue); // update or set value 
//         return ;
//     }
//     // Partial overlap

//     int left = node * 2;// 1 base indexing
//     int right = node * 2 + 1;
//     int mid = ( begin  + end) / 2;
//     update(left , begin, mid , i , newvalue);
//     update(right ,  mid + 1,end , i , newvalue);
//     tree[node] = min(tree[left] , tree[right]);
// }
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n  , m; 
    scanf("%d" ,&n) ;
    for(int i = 1; i <= n ; i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d", &m);
    // tree.resize(4*n);
    // for(int i = 1; i <= mx * 4 - 1 ; i++){
    //     tree[i] = 0;
    // }
    build(1, 1 , n);
    /* cout << query(1 , 1 , n , 1 , 3) << endl;
    update(1 ,1 , n , 2, 0);
    cout << query(1 , 1 , n , 1 , 3) << endl;
    update(1 ,1 , n , 2 , 5);
    cout << query( 1, 1 , n , 1 , 2 ) << endl; */
    while(m--){
        int k , l , r ;
        scanf("%d %d %d" , &l , &r , &k);
        cout << query(1 , 1 , n , l , r , k) << endl;
        
    }
}
