 
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

void solve(){
    int n;
    cin >> n;
    map<int , int>hash;
    vector<int>a(n) , b(n);
    for(auto &x:a){
        cin >> x;
        if(!hash[x]){
            hash[x] = rng();
        }
    }
    for(auto &x:b){
        cin >> x;
        if(!hash[x]){
            hash[x] = rng();
        }
    }
    vector<int>xora(n);
    vector<int>xorb(n);
    set<int>s;
    for(int i = 0 ; i< n; i++){
        if(s.find(a[i]) == s.end()){
            s.insert(a[i]);
            xora[i] = hash[a[i]];
        }
        if(i > 0) xora[i] ^= xora[i-1];
    }
    s.clear();
    for(int i = 0 ; i< n; i++){
        if(s.find(b[i]) == s.end()){
            s.insert(b[i]);
            xorb[i] = hash[b[i]];
        }
        if(i > 0) xorb[i] ^= xorb[i-1];
    }

    int q;
    cin >> q;
    for(int i = 0 ;i < q; i++){
        int x, y;
        cin >> x >> y;
        if(xora[x-1] == xorb[y-1]) {
            cout <<"Yes"<< sad;
        }
        else cout << "No"<< sad;
    }
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