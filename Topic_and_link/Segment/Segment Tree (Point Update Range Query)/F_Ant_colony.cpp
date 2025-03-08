#include<bits/stdc++.h>

using namespace std;
#define mx 100005 * 1LL
const int inf = 2000000000;
int arr[mx];
int tree1[mx * 4 ];// space 4 * N neya hoi contest er somoy but 3 * N neya better 
int tree2[mx * 4 ];// space 4 * N neya hoi contest er somoy but 3 * N neya better 
void build1(int node, int begin, int end) {
    if (begin == end) {
        tree1[node] = arr[begin];
        return;
    }
    int left =  2 * node;
    int right =  2 * node + 1;
    int mid = (begin + end) / 2;
    build1(left, begin, mid);
    build1(right, mid + 1, end);
    tree1[node] = min(tree1[left], tree1[right]); // Update tree1[node] with the min of left and right children
}

// segment tree1 query
// here i  and j is the starting and ending possition of given array or tree1
// begin and end is the of range query
//  
// query and update O(log(n))
int query1(int node , int begin , int end , int i , int j){
    if( i > end or j < begin){
        return inf;//No overlap 
    }
    if(begin >= i and end <= j){
        return tree1[node] ; // Total overlap;
    }
    // Partial overlap
    // jodi 0 index e hoi left = node * 2 + 1 , right = node * 2 + 2 hobe;
    int left = node * 2;// 1 base indexing
    int right = node * 2 + 1;
    int mid = ( begin  + end) / 2;
    int x = query1(left , begin, mid , i , j);
    int y = query1(right ,  mid + 1,end , i , j);
    return min( x  , y); // finding minimum range query
}
long long gcd(long long x, long long y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
void build2(int node, int begin, int end) {
    if (begin == end) {
        tree2[node] = arr[begin];
        return;
    }
    int left =  2 * node;
    int right =  2 * node + 1;
    int mid = (begin + end) / 2;
    build2(left, begin, mid);
    build2(right, mid + 1, end);
    tree2[node] = gcd(tree2[left], tree2[right]); // Update tree2[node] with the min of left and right children
}

// segment tree2 query
// here i  and j is the starting and ending possition of given array or tree2
// begin and end is the of range query
//  
// query and update O(log(n))
int query2(int node , int begin , int end , int i , int j){
    if( i > end or j < begin){
        return 0;//No overlap 
    }
    if(begin >= i and end <= j){
        return tree2[node] ; // Total overlap;
    }
    // Partial overlap
    // jodi 0 index e hoi left = node * 2 + 1 , right = node * 2 + 2 hobe;
    int left = node * 2;// 1 base indexing
    int right = node * 2 + 1;
    int mid = ( begin  + end) / 2;
    int x = query2(left , begin, mid , i , j);
    int y = query2(right ,  mid + 1,end , i , j);
    return gcd(x,y); // finding minimum range query
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n  , m; 
    cin >> n ;
    // in this problem we use gcd due to 
    // If an ant si divides all strengths in the range, 
    // it must be equal to the GCD of the range.
    map<int , vector<int>>mp;
    for(int i = 1; i <= n ; i++){
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }
    cin >> m;
    for(int i = 1; i <= mx * 4 - 1 ; i++){
        tree2[i] = inf;
        tree2[i] = 0;
    }
    build1(1, 1 , n);
    build2(1, 1 , n);
    /* cout << query(1 , 1 , n , 1 , 3) << endl;
    update(1 ,1 , n , 2, 0);
    cout << query(1 , 1 , n , 1 , 3) << endl;
    update(1 ,1 , n , 2 , 5);
    cout << query( 1, 1 , n , 1 , 2 ) << endl; */
    while(m--){
        int  l , r ;
        cin  >> l >> r;
        int minimumvalue = query1(1 ,1 , n , l , r);
        int g = query2(1 ,1 , n , l , r);
        int ans = r - l + 1;
        if(minimumvalue == g){
            ans -= upper_bound(mp[minimumvalue].begin() , mp[minimumvalue].end(), r)- mp[minimumvalue].begin();
            ans += lower_bound(mp[minimumvalue].begin() , mp[minimumvalue].end(), l)- mp[minimumvalue].begin();
        }
        cout << ans << endl;
    }
}