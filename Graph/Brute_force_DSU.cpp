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
long long parent[N] ;//create parent array;
void make(long long v){
    parent[v] = v;// indepent node make
}
long long find(long long v){
    if(v == parent[v]){
        return v;//parent or root find  of the group;
    }
    return find(parent[v]);//jotokkon parent pabo nah totokkon eta cholbhe;
}
void Union(long long a , long long b ){//create a set of group 
    a = find(a);//roots of a nodes group;
    b = find(b);// roots of b nodes group;
    if(a != b)//roots are different;
    {
        //parent of a added with parent of b then parent of a , b is parent of b;
        //parent of b added with parent of a then parent of a , b is parent of a;
        // but there is a problem when added a big tree to small parent tree as a result the length of tree is increase;
        //though we want to reduce the length or equal lenth of tree is much better than big tree;
        parent[b] = a;//parent of b added with parent of a then parent of a , b is parent of a;
        //solution of the above problem 2 ways(complexity same);
        //solution a;
        // 1 . base of size here we added the small tree with big tree;
        // 2 . rank(merge of tree);
        //solution b;
        // Path compression it is for find function actually reduce the length of tree;
    }
}
void solve(){

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