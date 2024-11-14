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
void solve()
{
    char a[2][2];
    set<char>s;
    for(long long i = 0; i < 2;i++){
        for(long long j = 0; j < 2; j++){
            cin >> a[i][j];
            s.insert(a[i][j]);
        }
    }
    if(s.size() == 1){
        cout << 0 << sad;
    }
    else{
        if(s.size() == 2){
            cout << 1 << sad;
        }
        else{
            if(s.size() > 3){
                cout << 3 << sad;
            }
            else{
                cout << 2 << sad;
            }
        }
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