#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mx 1000005 * 1LL
const int inf = 2000000000;
int arr[mx*3];
vector<int>g[mx*3];
double tree[mx * 12+5 ];// space 4 * N neya hoi contest er somoy but 3 * N neya better 
void build(int node, int begin, int end) {
    if (begin == end) {
        tree[node] = 0;
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
double query(int node , int begin , int end , int i , int j){
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
    double x = query(left , begin, mid , i , j);
    double y = query(right ,  mid + 1,end , i , j);
    return ( x  + y); // finding imum range query
}
void update(int node , int begin , int end , int i , double newvalue){
    if( i > end or i < begin){
        return ;//No overlap 
    }
    if(begin >= i and end <= i){
        tree[node]  = log10(newvalue); // update or set value 
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
int start[mx], finish[mx], flateing_tree[4*mx];
int timer = 1;
// dfs for Euler tour
// counting entering and leaving time for each node
void dfs(int node , int par){
    start[node] = timer-1;
    flateing_tree[timer] = node;
    timer++;
    for(auto &x:g[node]){
        if(x != par){
           dfs( x, node); 
        }
    }
    finish[node] = timer;
    flateing_tree[timer] = node;
    
} 
signed main(){
    int n  ; 
    cin >> n;
    for(int i = 1; i < n ;i++){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= mx * 4 - 1 ; i++){
        tree[i] = inf;
    }
    dfs(1 , 0);
    build(1, 1 , n);
    int m ;
    cin >> m;
    while(m--){
        int t , x , y;
        cin>> t >> x >> y;
        if(t == 1){
            
            update(1 , 1 , n , start[x], y * 1.0);
        }
        else{
            double ft = query(1 , 1 , n , start[x], finish[x]);
            double sec = query(1 , 1 , n , start[y], finish[y]);
            double ans  = (ft  - sec);
            if(ans >= 9.00000){
                cout << 1000000000 << endl;
            }
            else{
                cout << fixed<< setprecision(10) << pow(10 , ans) << endl;
            }
        }
    }
}