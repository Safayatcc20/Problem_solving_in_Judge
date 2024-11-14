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
void solve()
{
    long long n , q;
    cin >> n >> q;
    
    vector<long long>v(n) ;
    for(auto &x : v) {
        cin >> x;
    }
    long long j = 0;
    vector<long long> chk(n , 1) , wi(n , INT_MAX);
    for(long long i = 1; i < n ;i++){
        chk[i] = i;
        if(v[j] > v[i]){
            wi[i] = i;
        }
        else{
            wi[j] = i;
            j++;
        }
    }
    while(q--){
        long long i , k;
        cin >> i >> k;
        i--;
        if(wi[i] == INT_MAX){
            if(k >= chk[i]){
                cout << k - chk[i] + 1 << sad;
            }
            else{
                cout << "0" << sad;
            }
        }
        else{
            if(k >= chk[i]){
                cout << min(k , wi[i] - 1) - chk[i] + 1 << sad;
            }
            else{
                cout << "0" << sad;
            }
        }
    }
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