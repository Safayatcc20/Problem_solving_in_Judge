 
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
#define int long long
long long t = 1;
class TreeAncestor {
    int log;
    vector<int>depth;// for handling the not exist of kth ancestor
    vector<vector<int>>up;
public:
    TreeAncestor(int n, vector<int>& parent) {
        log = 0 ;
        while((1<<log) <= n){ // if give wrong answer then chcek to (1<<(log+1)) 
            log++;
        }
        up = vector<vector<int>>(log, vector<int>(n+1, -1));
        depth = vector<int>(n+1);
        up[0] = parent;
        for(int i = 1; i < log ;i++){
            for(int j = 1; j<= n ;j++){
                if(up[i-1][j] == -1) up[i][j] = -1;
                else up[i][j] = up[i-1][up[i-1][j]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        
        for(int j =  0 ; j < log ; j++) {
            if(node == -1){
                return -1;
            }
            if(k & (1 << j)) {
                node = up[j][node];
            }
        }
        return node;
    }
};
void solve(){
    int n , q;
    cin >> n >> q;
    vector<int>parent(n + 1, -1);
    for(int i = 2; i <= n; i++){
        cin >> parent[i];
    }
    TreeAncestor obj(n+1 , parent);
    for(int i = 0 ;i < q; i++){
        int employee , k;
        cin >> employee >> k;
        cout << obj.getKthAncestor(employee ,k) << sad;
    }
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