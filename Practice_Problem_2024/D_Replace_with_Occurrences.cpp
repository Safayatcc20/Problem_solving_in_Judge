
/***** Bismillahir Rahmanir Rahim *****/

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/// order_of_key(x) returns number of elements strictly less than x
/// find_by_order(x) return x th element of the set (0 based index)
/// less dile choto theke boro sajano
/// less equal dile multiset er moto kaj kore
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'

long long t = 1;
constexpr bool multiple_test_cases = 1;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> mp(n + 1);
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
        st.insert(v[i]);
        // cout << v[i] << " ";
    }
    // cout << sad;
    if (st.size() == n and n != 1)
    {
        cout << -1 << sad;
        return;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mp[i]){
            ans += i;
        }
    }
    // if (ans == n)
    // {
    //     int val = 1;
    //     vector<int> pp;
    //     for (int i = n; i > 0; i--)
    //     {
    //         if (mp[i])
    //         {
    //             mp[i]-=i;
    //             int temp = i;
    //             while (temp > 0)
    //             {
    //                 temp--;
    //                 pp.push_back(val);
    //                 //cout << val << " ";
    //             }
    //             val++;
    //         }
    //     }
    //     for(int i = 1 ; i<= n;i++){
    //         if(mp[i]){
    //             cout << -1 << sad;
    //             return;
    //         }
    //     }
    //     for(auto &x:pp) cout << x << " ";
    //     cout << sad;
    // }
    // else
    // {
        int val = 1;
        int res = 0;
        vector<int> pp;
        // for (int i = 1; i <= n; i++)
        // {
        //     int temp = i;
        //     if (mp[i])
        //     {
        //         res += i;
        //         mp[i] -= i;
        //         while (temp--)
        //         {
        //             pp.push_back(val);
        //             // cout << val << " ";
        //         }
        //         val++;
        //     }
        // }
        // if (res < n)
        // {
        //     for (int i = 1; i <= n; i++)
        //     {
        //         int temp = i;
        //         if (mp[i])
        //         {
        //             int baki = mp[i];
        //             while (baki > 0)
        //             {
        //                 if (res + i > n)
        //                 {
        //                     break;
        //                 }
        //                 res += i;
        //                 while (temp--)
        //                 {
        //                     pp.push_back(val);
        //                     // cout << val << " ";
        //                 }
        //                 val++;
        //                 if (res == n)
        //                 {
        //                     return;
        //                 }
        //                 if (val > n)
        //                 {
        //                     cout << -1 << sad;
        //                     return;
        //                 }
        //             }
        //         }
        //         if (res == n)
        //         {
        //             break;
        //         }
        //     }
        // }
        for(int i = 1; i <= n;i++){
            if(mp[i]) {
                res+= i;
                mp[i]-=i;
                int temp = i;
                while (temp--)
                {
                    pp.push_back(val);
                    // cout << val << " ";
                }
                val++;
            }
        }
        if(res < n){
            for(int i = 1; i <= n ;i++){
                if(mp[i]){
                    int rem = n - res;
                    int nibho = rem  / i;
                    int ache = nibho * i;
                    if(mp[i] >= ache){
                        res+=ache;
                        mp[i]-=ache;
                    }
                    else{
                        int take = min(ache , mp[i]);
                        int yeah = take / i;
                        nibho = yeah;
                        res += yeah*i;
                    }
                    while(nibho--){
                        int temp = i;
                        while(temp--){
                            pp.push_back(val);
                        }
                        val++;
                    }
                    if(res == n){
                        break;
                    }
                }
                if(res == n){
                    break;
                }
            }
        }
        if(res < n){
            cout << -1 << sad;
            return;
        }
        else if(res == n and val > n+1){
            cout << -1 << sad;
            return;
        }
        for(int i = 1 ; i<= n;i++){
            if(mp[i]> 0 or mp[i]< 0){
                cout << -1 << sad;
                return;
            }
        }
        for (auto &x : pp)
            cout << x << " ";
        cout << sad;
    // }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        // cout << "test "<< i << sad;
        solve();
    }
}