/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
void solve()
{
    long long n ;
    cin >> n ;
    long long z = 0 , sum = 0;
    vector<long long> v(n);
    map<long long , long long>mp;
    for(long long i = 0; i < n ; i++){
        cin >> v[i];
    }
    bool flag = true;
    for(long long i = 0; i <  n - 1; i++){
        if(v[i] == 0  && flag){
            continue;
        }
        if(v[i] > 0){
            sum += v[i];
            flag =false;
        }
        else{
            z++;
        }
    }
    cout << sum + z << sad;
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