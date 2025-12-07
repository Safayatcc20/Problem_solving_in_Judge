 
 /***** Bismillahir Rahmanir Rahim *****/

#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using oset = tree<T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/// order_of_key(x) returns number of elements strictly less than x
/// find_by_order(x) return x th element of the set (0 based index)
///less dile choto theke boro sajano
///less equal dile multiset er moto kaj kore
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
#define int long long
long long t = 1;
constexpr bool multiple_test_cases = 1;


long long rng() {
	static std::mt19937 gen(
	    std::chrono::steady_clock::now().time_since_epoch().count());
	return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}
struct SegTree {
    int n;
    vector<int> tree;
    vector<int>& a;
    
    SegTree(vector<int>& arr) : a(arr) {
        n = a.size();
        tree.resize(4*n);
        build(1, 0, n-1);
    }

    void build(int node, int l, int r) {
        if(l == r) {
            tree[node] = l;
            return;
        }
        int m = (l+r)/2;
        build(2*node, l, m);
        build(2*node+1, m+1, r);
        int li = tree[2*node], ri = tree[2*node+1];
        tree[node] = (a[li] >= a[ri] ? li : ri);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) return -1;
        if(ql <= l && r <= qr) return tree[node];
        int m = (l+r)/2;
        int left = query(2*node, l, m, ql, qr);
        int right = query(2*node+1, m+1, r, ql, qr);
        if(left == -1) return right;
        if(right == -1) return left;
        return (a[left] >= a[right] ? left : right);
    }

    int getMaxIndex(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};
void solve(){
    int n;
    cin >> n;
    map<int , int>hash;
    vector<int>a(n) , b(n);
    for(auto &x:a){
        cin >> x;
        if(hash.count(x) == 0) hash[x] = rng();
    }
    vector<int>good(n+1 , 0);
    for(int i = 1; i <= n ;i++){
        good[i] = good[i-1] ^ hash[i];
    }
    vector<int>xora(n);
    vector<int>xorb(n);
    set<int>s;
    for(int i = 0 ; i< n; i++){
        if(i > 0) xora[i] = xora[i-1] ^ hash[a[i]];
        else xora[i] = hash[a[i]];
    }
    
    int ans = 0 ;
    stack<pair<int , int>>st;
    st.push({0 , n - 1});
    SegTree seg(a);
    while(!st.empty()){
        auto x = st.top();
        int l = x.first;
        int r = x.second;
        st.pop();
        if( l > r) continue;
        int mxind = seg.getMaxIndex(l,r);

        int len = a[mxind];

        if(mxind - l < r -mxind){
            int st = max(l , mxind - len+1);
            for(int i = st; i <= mxind;i++){
                if(len + i - 1 > r) break;
                int val = 0 ;
                if(i > 0) val = xora[i-1];
                else val = 0;
                if((xora[len + i - 1] ^ val) == good[len]) ans++; 
            }
        }
        else{
            int st = min(r , mxind + len-1);
            for(int i = st; i >= mxind;i--){
                if( i - len + 1 < l) break;
                int val = 0 ;
                if(i - len + 1 > 0) val = xora[i - len];
                else val = 0;
                if((xora[i] ^ val) == good[len]) ans++; 
            }
        }
        
        if(l<mxind) st.push({l, mxind-1});
        if(mxind<r) st.push({mxind+1, r});
    }

    cout << ans << sad;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}