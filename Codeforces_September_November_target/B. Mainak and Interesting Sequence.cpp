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
    long long n, m;
    cin >> n >> m;
    if(n==1) {
        cout << "YES\n" << m << sad;
        return ;
    }
    if(n > m ){
        cout << "NO" << sad;
        return;
    }
    if(n % 2 == 0 && m % 2){
        na;
    }
    else {
        cout << "YES" << sad;
        long long sum = m;
        for(long long i = 1 ; i < n-1; i++) {
            if(i == n) {
                cout << sum << " ";
            }
            else {
                cout << 1 << " ";
                sum --;
            }
        }
        if(n % 2) {
            cout << 1 << " " <<(sum-1) << sad;
        }
        else {
            cout << sum / 2 << " " << sum / 2<< sad;
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