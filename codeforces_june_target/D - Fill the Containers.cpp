/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define end '\n'
long long m; 
long long find(long long cap ,long long n, vector<long long> &v){
    long long sum = 0 , cnt = 0;
    for(long long  i = 0; i < n ;i++){
        sum += v[i];
        if(sum <= cap){
            sum = sum;
        }
        else{
            sum = v[i];
            cnt++;
        }
    }
    if(cnt + 1 > m){
        return 0;
    }
    return 1;
}
long long search(long long l  , long long r , vector<long long> &v){
    long long result = 0;
    while(l <= r){
        long long mid = (l + r) / 2;
        if(find(mid , v.size(), v)){
            result = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return result;
}
void solve()
{
    long long n ;
    while(cin >> n >> m){
        vector<long long>v(n);
        long long r = 0 , l = 0;
        for(auto &x:v){
            cin >> x;
            r += x;
            l = max(l , x);
        }
        cout << search(l , r , v) << "\n";
        
    }
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   /*  long long t;
    cin >> t;
    while(t--){ */
        solve();
    //}
}