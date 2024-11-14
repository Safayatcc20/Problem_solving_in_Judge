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
    long long n , k , b , s;
    cin >> n >> k >> b >> s;
    if(n == 1){
        if(k * b == s){
            cout << k * b << sad;
        }
        else{
            cout << -1 << sad;
        }
        return;
    }
    if(k * b > s ||  n * (k - 1) + k * b < s){
        cout << - 1 << sad;
        return;
    }
    vector<long long>v(n);
    v[0] = k * b ;
    s -= k * b ;
    for(long long i = 1; i < n ; i++){
        if(s > 0){
            v[i] = min(k - 1 , s);
            s -= min(k-1 , s);
        }
    }
    for(long long i = n-1; i >= 0; i--){
        cout << v[i] << " ";
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