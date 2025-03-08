/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define end '\n'
void no1(vector<long long> &v , vector<long long> &p, vector<long long> &s, long long n){
    p[0] = v[0];
    for(long long i = 1; i< n ;i++){
        p[i] = __gcd(p[i-1] , v[i]);
    }
    s[n-1] = v[n-1];
    for(long long i= n - 2; i >= 0; i--){
        s[i] = __gcd(s[i+1], v[i]);
    }
}
long long noo(long long i , vector<long long> &p , vector<long long> &s ,long long n){
    if(i == 0) return s[i+1];
    if(i == n - 1) return p[i-1];
    return __gcd(p[i-1] , s[i+1]);
}
void solve()
{
    long long n;
    cin >> n;
    vector<long long>v(n) , p(n) , s(n);
    long long mn = INT_MAX;
    for(auto &x:v){
        cin >> x;
    }
    no1(v, p , s , n);
    long long res = 0;
    for(long long i = 0 ; i < n ;i++){
        if(noo(i , p , s , n) > 1){
            res++;
        }
    }
    cout << res << end;
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