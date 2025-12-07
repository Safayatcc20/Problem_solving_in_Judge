/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
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
const long long N = 1000005;
long long parent[N] , sz[N] ;//create parent array;
void make(long long v){
    parent[v] = v;// indepent node make
    sz[v] = 1;
}
long long find(long long v){
    if(v == parent[v]){
        return v;//parent or root find  of the group;
    }
    // path compression is here
    return parent[v] = find(parent[v]);//change the parent;
}
void Union(long long a , long long b ){//create a set of group 
    a = find(a);//roots of a nodes group; it is left tree(big size tree always);
    b = find(b);// roots of b nodes group; it is right tree(small size tree always);
    if(a != b)//roots are different;
    {
        //union by size
        if(sz[a] < sz[b]){// if a is small size tree then make a is big and b is small;
            swap(a , b);
        }
        parent[b] = a;//parent of b added with parent of a then parent of a , b is parent of a;
        sz[a] += sz[b];//size of a and b are now group;
        //problem solve by size cocept;
    }
}
void solve(){
    // DSU time complexity O(alpha(n));
    // herer alpha(n) is called Reverse ackerman function;it is increase the value so slowly;
    //cp algorithm discuss this code see here link below:
    //https://cp-algorithms.com/data_structures/disjoint_set_union.html#search-for-connected-components-in-an-image'
    long long n , k;
    cin >> n >> k;
    for(long long i = 1; i <= n; i++) make(i);
    while(k--){
        int u , v;
        cin >> u >> v;
        Union(u , v);
    }
    int connected_component = 0;// how many roots is the connected component;
    for(long long i =  1; i <= n ; i++){
        if(i == find(i)){
            connected_component++;
        }
    }
    cout << connected_component << sad;
}
int main()
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