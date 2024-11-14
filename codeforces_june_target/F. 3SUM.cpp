/*
   **** Author: Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n ;
    cin >> n;
    long long odd = 0, even = 0;
    vector<long long>v(n),e(10),o;
    for(auto &x:v){
        cin >> x;
        if(e[x % 10] < 3){
            e[x%10]++;
            o.push_back(x % 10);
        }
        
    }
    for(long long i = 0; i < o.size(); i++){
        for(long long j = i+1; j < o.size(); j++){
            for(long long k = j + 1; k < o.size() ;k++){
                if((o[i]+o[j]+o[k] )% 10 == 3){
                    cout << "YES" << "\n";
                    return;
                }
            }
        }
    }
    cout << "NO" << "\n";
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