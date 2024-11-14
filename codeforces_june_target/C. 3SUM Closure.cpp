/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
void solve()
{
    long long n , oo = 0;
    cin >> n;
    vector<long long>v(n);
    for(auto &x: v){
       cin >> x;
       if(x != 0 && oo < 3){
            oo++;
            
            continue;
       }
    }
    sort(v.begin() , v.end());
    if(n > 3){
        if(v[0] < 0 && v[1] < 0 && v[2] < 0 || v[n-1] > 0 && v[n-2] > 0 && v[n-3] > 0){
            cout << "NO" << endl;
            return;
        }
    }
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n  && j != i; j++){
            for(long long k = 0; k < n && k != i && k != j; k++){
                long long sum = v[i] + v[j] + v[k];
                long long kk = binary_search(v.begin(), v.end(), sum) ;
                //cout << kk << " ";
                if(kk == 0){
                    cout << "NO" << endl;
                    return ;
                }
            }
        }
    }
    cout << "YES" << endl;
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