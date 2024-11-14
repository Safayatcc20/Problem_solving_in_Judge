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
    long long n;
    cin >> n ;
    vector<string>f(n) , s(n) , t(n);
    set<string>fm , sm , tm;
    for(long long i = 0; i < n ; i++){
        cin >> f[i];
        //cout << f[i] << sad;
        fm.insert(f[i]);
    }
    for(long long i = 0; i < n ; i++){
        cin >> s[i];
        //cout << s[i] << sad;
        sm.insert(s[i]);
    }
    for(long long i = 0; i < n ; i++){
        
        cin >> t[i];
        //cout << t[i] << sad;
        tm.insert(t[i]);
    }
    long long a = 0 , b = 0  , c = 0;
    for(long long i = 0; i < n ;i++){
        if(sm.find(f[i]) == sm.end() && tm.find(f[i]) == tm.end()){
           // cout << f[i] << sad;
            a += 3;
        }
        else if(sm.find(f[i]) == sm.end() || tm.find(f[i]) == tm.end()){
            a += 1;
        }
    }
    for(long long i = 0; i < n ;i++){
        if(fm.find(s[i]) == fm.end() && tm.find(s[i]) == tm.end()){
            b += 3;
            //cout << s[i] << sad;
        }
        else if(fm.find(s[i]) == fm.end() ||tm.find(s[i]) == tm.end()){
            b += 1;
        }
    }
    for(long long i = 0; i < n ;i++){
        if(sm.find(t[i]) == sm.end() && fm.find(t[i]) == fm.end()){
            c += 3;
            //cout << t[i] << sad;
        }
        else if(sm.find(t[i]) == sm.end() || fm.find(t[i]) == fm.end()){
            c += 1;
        }
    }
    cout << a << " "  << b << " " << c << sad;
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