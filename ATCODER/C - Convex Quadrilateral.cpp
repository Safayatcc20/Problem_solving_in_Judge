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
    vector<vector<long long>>a(4);
    for(long long i = 0; i < 4 ; i++){
        for(long long j = 0; j < 4 ; j++){
            cin >> a[i][j];
        }
    }
    long long prev = 0 ,chk  = 0 , p = 0 , cu = 0;
    long long d = 0 , b = 0 , mm = 0;
    for(long long i = 0; i < 4 ; i++){
        vector<vector<long long>> v;
        v = {a[i] , a[i+1] , a[i+2]};
        p = v[1][0] - v[0][0];
        cu = v[1][1] - v[0][1];
        d = v[2][0] - v[0][0];
        b = v[2][1] - v[0][1];
        mm = p * d - cu * b;
        cout << mm << sad;
        if(mm != 0){
            if(mm *prev < 0){
                cout << "No" << sad;
            }
            else{
                prev = mm;
            }
        }
        else{
            cout << sad;
        }
    }

}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //long long t;
    //cin >> t;
    while(t--){
        solve();
    }
}