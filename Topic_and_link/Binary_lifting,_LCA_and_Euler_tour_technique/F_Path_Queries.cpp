#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mx 1000000 * 1LL

const int inf = 2000000000;
int start[mx*4], finish[mx*4], flateing_tree[4*mx];
int timer = 0;
int arr[mx ];
vector<int>g[mx*3];
double tree[mx * 4 ];// space 4 * N neya hoi contest er somoy but 3 * N neya better 
void build(int node, int begin, int end) {
    if (begin == end) {
        tree[node] = arr[flateing_tree[begin]];
        return;
    }
    int left =  2 * node;
    int right =  2 * node + 1;
    int mid = (begin + end) / 2;
    build(left, begin, mid);
    build(right, mid + 1, end);
    tree[node] = (tree[left] +  tree[right]); // Update tree[node] with the  sum of left and right children
}

// segment tree query
// here i  and j is the starting and ending possition of given array or tree
// begin and end is the of range query
//  
// query and update O(log(n))
int query(int node , int begin , int end , int i , int j){
    if( i > end or j < begin){
        return 0;//No overlap 
    }
    if(begin >= i and end <= j){
        return tree[node] ; // Total overlap;
    }
    // Partial overlap
    // jodi 0 index e hoi left = node * 2 + 1 , right = node * 2 + 2 hobe;
    int left = node * 2;// 1 base indexing
    int right = node * 2 + 1;
    int mid = ( begin  + end) / 2;
    int x = query(left , begin, mid , i , j);
    int y = query(right ,  mid + 1,end , i , j);
    return ( x  + y); // finding imum range query
}
void update(int node , int begin , int end , int i , double newvalue){
    if( i > end or i < begin){
        return ;//No overlap 
    }
    if(begin == end ){
        tree[node]  = newvalue; // update or set value 
        return ;
    }
    // Partial overlap

    int left = node * 2;// 1 base indexing
    int right = node * 2 + 1;
    int mid = ( begin  + end) / 2;
    update(left , begin, mid , i , newvalue);
    update(right ,  mid + 1,end , i , newvalue);
    tree[node] = (tree[left] + tree[right]);
}
// dfs for Euler tour
// counting entering and leaving time for each node
void dfs(int node , int par){
    timer++;
    start[node] = timer;
    flateing_tree[timer] = node;
    for(auto &x:g[node]){
        if(x != par){
           dfs( x, node); 
        }
    }
    finish[node] = timer;
    // flateing_tree[timer] = node;
} 
   
    

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n  , m; 
    cin >> n >> m;
    for(int i = 1; i <= n ;i++){
        cin >> arr[i];
    }
    for(int i = 0 ; i < n - 1; i++){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    // range timer e dithe hobe karon linear korle range n er beshi hobe 
    build(1 , 1 , timer);
    for(int i = 1;i <= n ;i++){
        update(1 ,1 , n , start[i] ,arr[i]);
        update(1 , 1,  n , finish[i]+1 , -arr[i]);
    }
    for(int i= 0 ;i < m ; i++){
        int t;
        cin >> t;
        if(t ==1 ){
            int x , y;
            cin >> x >> y;
            update(1 , 1 , timer , start[x] , y);
        }
        else{
            int x;
            cin >> x;
            cout << query(1 , 1 , timer , 1, start[x]-1) << endl;
        }
    }
}