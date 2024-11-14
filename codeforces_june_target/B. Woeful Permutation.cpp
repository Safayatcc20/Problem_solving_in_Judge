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
    if(n == 1){
        cout << 1 <<sad;
        return;
    }
    vector<long long>v(n);
    for(long long i = 0; i < n ; i++){
        v[i] = i + 1;
    }
    if(n % 2){
        for(long long i = 1; i < n ;i+= 2){
            swap(v[i] , v[i+1]);
        }
        for(auto &x:v) {
            cout << x << " ";
        }
        cout << sad;
        return;
    }
    for(long long i = 0; i < n ;i+= 2){
        swap(v[i] , v[i+1]);
    }
    for(auto &x:v) {
        cout << x << " ";
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