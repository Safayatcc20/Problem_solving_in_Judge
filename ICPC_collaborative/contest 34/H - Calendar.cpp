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
bool sorrt(pair<long long , long long>a , pair<long long , long long>b){
    return (a.first > b.first || (a.first == b.first && a.second < b.second));
}
void solve()
{
    long long n;
    cin >> n ;
    vector<pair<long long , long long>>a;
    vector<long long> c(n);
    long long carry = 0;
    for(long long i = 0; i < n ; i++){
        long long x , y;
        cin >> x >> y >> c[i];
        a.push_back({x , y});
        carry = max(carry , c[i]);
    }
    vector<long long>sum(12 , 0);
    sum[0] = 31;
    for(long long i = 1 ; i < 12; i++){
        if(i == 1){
            sum[i] = sum[i-1] + 28;
        }
        else if(i % 2 == 0 || i == 7 || (i > 5 && i % 2 == 0)){
            sum[i] = sum[i-1] + 31;
        }
        
        else{
            sum[i] = sum[i-1] + 30;
        }
    }
    sort(all(a) , sorrt);
    long long mon = a[n-1].first , day = a[n-1].second-1;
    //cout << day << " " << mon << sad;
    if(mon == 1){
        cout << max(day , carry) << sad;
        return;
    }
    long long cal = sum [mon - 2] + day;
    //cout << sum [mon - 1 ] << sad;
    cout << max(cal , carry) << sad;
    //for(auto &x:sum) cout << x << " " ;
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