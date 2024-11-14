/*
   **** Bismillahir Rahmanir Rahim ****
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
void solve()
{
    long long n ;
    cin >> n ;
    vector<long long>v(n);
    for(auto &x:v) cin >> x ;
    long long pr = 0 , suf = 0;
    long long al = 0 , b = 0;
    long long i = 0 , cnt  = 0 ,j = n - 1;
    while(i<= j){
        if(pr <= suf){
            pr += v[i];
            i++;
            al++;
        }
        else{
            suf += v[j];
            j--;
            b++;
        }
        if(suf == pr){
            cnt = b + al;
        }
    }
    cout << cnt << sad;
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}