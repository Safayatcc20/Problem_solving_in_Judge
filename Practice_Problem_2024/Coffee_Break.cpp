 
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
void solve(){
    string s;
    cin >> s;
    int a = 0 , b = 0;
    a = (s[0] - '0')*10 + (s[1] - '0');
    b = (s[3] - '0')*10 + (s[4] - '0');
    if(a == 0 and b == 0){
        cout << "00:00"<< sad;
    }
    else if(a <= 11){
        if(a != 11) cout << "11:11"<< sad;
        else if(a == 11 and b <= 11){
            cout << "11:11" << sad;
        }
        else cout << "22:22"<< sad;
    }
    else if(a <= 22 ){
        if(a != 22) cout << "22:22"<< sad;
        else if(a == 22 and b <= 22){
            cout << "22:22" << sad;
        }
        else cout << "00:00"<< sad;
    }
    else{
        cout << "00:00"<< sad;
    }
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