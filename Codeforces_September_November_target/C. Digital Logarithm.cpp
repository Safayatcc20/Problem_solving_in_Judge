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
long long gcd(long long x , long long y){
  if(y == 0) return x;
  return gcd(y , x % y);
}
long long lcm(long long x , long long y){
  return (( x * y) /gcd(x , y));
}
void solve()
{
    long long n ;
    cin >> n ;
    vector<long long>v(n) , vv(n);
    priority_queue<long long>d, dd;
    map<long long , long long>mp;

    for(auto &x:v) {
        cin >> x;
        mp[x] = 1;
    }
    for(auto &x:vv) {
        cin >> x;
        //mp[x] = 1;
    }
    sort(all(v));
    sort(all(vv));
    for(auto &x:v){
        d.push(x);
    }
    for(auto &x:vv){
        dd.push(x);
    }
    bool flag = false;
    long long ans = 0 , no = 0;
    long long sz = d.size(), chk = 0;
    while (!d.empty())
    {
        long long a = d.top();
        long long b = dd.top();
        //cout << a << " " << b << sad;
        if(a == b){
            d.pop();
            dd.pop();
            continue;
        }
        else if(a > b){
            d.pop();
            no = log10(a)+1;
            d.push(no);
            ans++;
        }
        else {
            dd.pop();
            no = log10(b)+1;
            dd.push(no);
            ans++;
        }
    }
    cout << ans  << sad;    
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //long long t;
    cin >> t;
    while(t--){
        solve();
    //cout << log10(611271314) << sad;
    }
}