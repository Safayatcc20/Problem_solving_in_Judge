/*
   **** Bismillahir Rahmanir Rahim ****
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
void solve()
{
    long long n;
    cin >> n ;
    cout << n << sad;
    vector<long long>v;
    for(long long i = 1; i <= n ;i++){
        v.push_back(i);
    }
    for(auto &x:v) cout << x << " ";

    cout <<sad;
    for(long long i = 0; i < n - 1; i++){
        swap(v[i] , v[i+1]);
        for(long long j = 0; j < n; j++){
            cout << v[j] << " ";
        }
        cout << sad;
    }
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}