#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mx = 3e5+10;
const int inf = 2000000000;
int arr[mx];
vector<int>g[mx];
double tree[mx * 4+5 ];// space 4 * N neya hoi contest er somoy but 3 * N neya better 
int start[mx], finish[mx], flateing_tree[mx];
int timer = 0;

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

double query(int node , int begin , int end , int i , int j){
    if( i > end or j < begin){
        return 0;//No overlap 
    }
    if(begin >= i and end <= j){
        return tree[node] ; // Total overlap;
    }
    // Partial overlap
    int left = node * 2;// 1 base indexing
    int right = node * 2 + 1;
    int mid = ( begin  + end) / 2;
    double x = query(left , begin, mid , i , j);
    double y = query(right ,  mid + 1,end , i , j);
    return x + y; // finding imum range query
}

void update(int node , int begin , int end , int i , double newvalue){
    if( i > end or i < begin){
        return ;//No overlap 
    }
    if(begin == end){
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

void dfs(int node , int par){
    timer++;
    start[node] = timer;
    for(auto &x:g[node]){
        if(x != par){
           dfs( x, node); 
        }
    }
    finish[node] = timer;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; 
    cin >> n;
    
    for(int i = 1; i < n ;i++){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1 , 0);
    build(1, 1 , n);
    int m;
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
