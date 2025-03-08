 
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
// Linear Diophantine Equation ax + by = c;
//solution by using  Extended Euclidean algorithm one solution
int extgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int n ;
vector<bool>visit, assignment;
vector<int>order,pos;
vector<vector<int>>g;
void dfs1(int v){
    visit[v] = true;
    for(auto &x:g[v]){
        if(!visit[x]) dfs1(x);
    }
    order.push_back(v);
}
void dfs2(int v , int cl){
    pos[v]= cl;
    for(auto &x:g[v]){
        if(pos[x] == -1) dfs2(x , cl);
    }
}
bool solve_2SAT(){
    visit.assign(n , false);
    for(int i = 0 ; i < n ;i++){
        if(!visit[i]) dfs1(i);
    }

    pos.assign(n , -1);
    for(int i = 0 , j = 0 ;i < n ;i++){
        int v = order[n-i-1];
        if(pos[v] == -1){
            dfs2(v , j++);
        }
    }
    assignment.assign(n / 2, false);
    for(int i = 0 ;i < n ; i+=2){
        if(pos[i] == pos[i+1]){
            return false;
        }
        assignment[i/2] = pos[i] > pos[i+1];
    }
    return true;
}
void solve(){
  //2-SAT problem
  cin >> n;
  vector<vector<int>>v(3 , vector<int>(n));
  for(int i = 0; i < 3; i++){
    for(int j= 0;j < n; j++){
        cin >> v[i][j];
    }
  }
  for(int i = 0;i < 2; i++){
    for(int j = 0 ;j < n - 1; j++){
        int x = abs(v[i][j]);
        int y = abs(v[i][j+1]);
        int z = abs(v[i+1][j]);
        g[x].push_back(y);
        g[x].push_back(z);
        g[y].push_back(x);
        g[z].push_back(x);
    }
  }
  for(int i = 2;i < 3; i++){
    for(int j = 0 ;j < n - 1; j++){
        int x = abs(v[i][j]);
        int y = abs(v[i][j+1]);
        g[x].push_back(y);
        g[y].push_back(x);
    }
  }
  if(solve_2SAT()) ha;
  else na;
}
int32_t main()
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