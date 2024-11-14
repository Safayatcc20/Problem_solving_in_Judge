/*
   **** Bismillahir Rahmanir Rahim ****
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
long long t = 1;
void solve()
{
    long long n;
    cin >> n;
    vector<long long>v(n);
    set<long long>s;
    for(auto &x:v) {
        cin >> x;
        s.insert(x);
    }
    if(s.size() == 1){
        for(auto &x:v){
            cout << x << " ";
        }
        cout << sad;
        return;
    }
    for(long long i = 0; i < n ;i++){
        if(i % 2){
            if(v[i] < 0){
                cout << abs(v[i]) << " ";
            }
            else{
                cout << v[i] << " ";
            }
        }
        else{
            if(v[i] < 0){
                cout << v[i] << " " ;
            }
            else{
                cout << -v[i] << " ";
            }
        }
    }
    cout << sad;
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