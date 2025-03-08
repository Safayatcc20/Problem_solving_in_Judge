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
    long long n ;
    cin >> n;
    vector<string>v(n);
    for(auto &x:v) cin >> x;
    sort(all(v));
    long long sum = 0;
    string s = "";
    for(long long i = n - 1; i >n-4; i--){
        s += v[i];
    }
    sort(all(s));
    for(long long i = s.size()-1; i >= 0; i--){
        cout << s[i];
    }
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
        solve();
    //}
}