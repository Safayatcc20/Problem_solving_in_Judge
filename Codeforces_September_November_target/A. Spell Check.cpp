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
    map<char , long long> mp;
    bool flag = true;
    long long cnt = 0;
    for(long long i = 0; i < n ; i++){
        if(s[i] == 'T' || s[i] == 'i' || s[i] == 'm'  || s[i] == 'u' || s[i] ==  'r'){
            cnt++;
            mp[s[i]]++;
            if(mp[s[i]] > 1){
                flag = false;
                break;
            }
        }
        else{
            flag = false;
            break;
        }
    }
    if(flag && cnt == 5){
        ha;
    }
    else{
        na;
    }
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