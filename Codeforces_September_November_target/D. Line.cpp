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
    string s;
    cin >> s;
    if(n == 1){
        cout << 0 << sad;
        return;
    }
    vector<long long> v , res;
    long long cnt = 0;
    for(long long i = 0; i < n ; i++){
        if(s[i] == 'R'){
            cnt += (n - i - 1);
        }
        else{
            cnt += i;
        }
        if(i < (n - i - 1) && s[i] == 'L'){
            v.push_back(n - 1 - i -  i);
        }
        else if( i > (n - i - 1) && s[i] == 'R'){
            v.push_back(i + i + 1 -  n);
        }
    }
    sort(v.rbegin() , v.rend());
    long long ans = 0;
    long long d = v.size();
    for(long long i = 0; i < d; i++){
        ans += v[i];
        res.push_back(cnt + ans);
    }
    for(long long i = d; i < n; i++){
        res.push_back(cnt + ans);
    }
    for(long long i = 0; i < n; i++){
        cout << res[i] << " ";
    }
    cout << sad;
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //long long t;
    cin >> t;
    while(t--){
        solve();
    }
}