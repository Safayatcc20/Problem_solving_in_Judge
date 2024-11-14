#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mx 4000010 * 1LL
const int inf = 2000000000;
int arr[mx] , suf[mx] , pre[mx] , seg[mx];
map<int , int>mp;
int tree[mx * 3];// space 4 * N neya hoi contest er somoy but 3 * N neya better 
void build(int node, int begin, int end) {
    if (begin == end) {
        tree[node] = arr[begin];
        pre[node] = max(0LL , arr[begin]);
        suf[node] = max(0LL , arr[begin]);
        seg[node] = max(0LL , arr[begin]);
        return;
    }
    int left =  2 * node;
    int right =  2 * node + 1;
    int mid = (begin + end) / 2;
    build(left, begin, mid);
    build(right, mid + 1, end);
    tree[node] = (tree[left] +  tree[right]); // Update tree[node] with the  sum of left and right children
    pre[node] = max(pre[left] , pre[right] +  tree[left]); // Update tree[node] with the  sum of left and right children
    suf[node] = max(suf[right] , suf[left] +  tree[right]); // Update tree[node] with the  sum of left and right children
    seg[node] = max({seg[left] , seg[right]  ,suf[left] + pre[right]}); // Update tree[node] with the  sum of left and right children
}

// segment tree query
// here i  and j is the starting and ending possition of given array or tree
// begin and end is the of range query
//  
// query and update O(log(n))
int query(int node , int begin , int end , int i ){
    
    if(begin == end){
        return begin; // Total overlap;
    }
    // Partial overlap
    // jodi 0 index e hoi left = node * 2 + 1 , right = node * 2 + 2 hobe;
    int left = node * 2;// 1 base indexing
    int right = node * 2 + 1;
    int mid = ( begin  + end) / 2;
    if(tree[left] >= i){
        //cout << i << endl;
        return query(left , begin , mid , i);
    }
    else {
       //cout << i << "me" << endl;
       //cout << tree[right] << endl;
        return query(right , mid + 1 , end , i - tree[left]);
    }
}
void update(int node , int begin , int end , int i , int val){
    
    if(begin == end){
        arr[i] = val;
        tree[node]  = arr[i]; // update or set value
        pre[node] = max(0LL , val);
        suf[node] = max(0LL , val);
        seg[node] = max(0LL , val);
        return ;
    }
    // Partial overlap

    int left = node * 2;// 1 base indexing
    int right = node * 2 + 1;
    int mid = ( begin  + end) / 2;
    if(begin <= i and  i <= mid)
    update(left , begin, mid , i, val);
    else update(right ,  mid + 1,end , i , val);
    tree[node] = (tree[left] +  tree[right]); // Update tree[node] with the  sum of left and right children
    pre[node] = max(pre[left] , pre[right] +  tree[left]); // Update tree[node] with the  sum of left and right children
    suf[node] = max(suf[right] , suf[left] +  tree[right]); // Update tree[node] with the  sum of left and right children
    seg[node] = max({seg[left] , seg[right]  ,suf[left] + pre[right]}); // Update tree[node] with the  sum of left and right children
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , m ; 
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }
    for(int i = 1; i <= mx * 3 - 1 ; i++){
        tree[i] = 0;
    }
    build(1, 1 , n);
    /* cout << query(1 , 1 , n , 1 , 3) << endl;
    update(1 ,1 , n , 2, 0);
    cout << query(1 , 1 , n , 1 , 3) << endl;
    update(1 ,1 , n , 2 , 5);
    cout << query( 1, 1 , n , 1 , 2 ) << endl; */
    
    for(int i = 1; i <= m;  i++){
        int t ,ind , val;
        cin >> t >> ind >> val;
        if(t == 0 ) {
            mp[arr[ind]]--;
            update(1 , 1 , n , ind , val);
            mp[arr[ind]]++;
        }
        else{
        }
        for(int i = 1; i <= n ;i++){
            cout << arr[i] << " "<<mp[arr[i]] << endl;
        }
        cout << endl;
    }
    cout << endl;
}