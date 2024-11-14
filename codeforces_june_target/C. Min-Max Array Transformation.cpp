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
    long long n;
    cin >> n ;
    long long cnt = 0;
    vector<long long>a(n) , b(n);
    for(auto &x:a) cin >> x;
    for(auto &x:b) cin >> x;
    sort(all(b));
    long long flag = 0;
    for(long long i = 0; i < n ; i++){
        for(long long j = 0; j < n ; j++){
           // cout << " u" <<i << b[i] - a[j] << sad;
            if(b[i] - a[j] >= 0){
                cnt++;
                if(cnt <= n){
                    cout << b[i] - a[j] << " " ;
                }
                else{
                    flag = 1;
                    break;
                }
            }
            else{
                i++;
                j--;
            }
        }
        if(flag ){
            break;
        }
    }
    cout << sad;
    long long chk = 0;
    for(long long i = 0; i < n; i++){
        chk = max(chk , i);
        //cout << chk << sad;
        while(chk < n - 1 && a[chk+1] <= b[chk]){
            chk++;
        }
        cout << b[chk] - a[i] << " ";
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