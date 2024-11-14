/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
long long t = 1;
constexpr bool multiple_test_cases = 1;
long long gcd(long long x, long long y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
long long lcm(long long x, long long y)
{
    return ((x * y) / gcd(x, y));
}
const long long N = 10000;
long long prime[N];
long long fact(long long n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
long long findXor(long long n){//reming: function calling findXor(sending value - 1);
    long long rest = n % 4;
    if(rest == 0) return n;
    if(rest == 1) return 1;
    if(rest == 2) return n+1;
    if(rest == 3) return 0;
}
void solve(){
    int cnt = 1, n = 15;
    vector<vector<int>>v(15 , vector<int>(15));
    for(int i = 0 ; i < cnt; i++){
        for(int j = 0 ; j < n ; j++){
            if(j == 0 || j == 1 || j == 2 || j == 4 || j == 6 || j == 9 || j == 8 || j == 10){
                v[i][j] = 1;
            }
        }
    }
    cnt++;
    for(int i = 1; i < cnt; i++){
        for(int j = 0 ; j < n ; j++){
            if(j == 1 || j == 4 || j == 6 || j == 8 ){
                v[i][j] = 1;
            }
        }
    }
    cnt++;
    for(int i = 2 ; i < cnt; i++){
        for(int j = 0 ; j < n ; j++){
            if( j == 1 || j == 5 || j == 4 || j == 6 || j == 9 || j == 8 || j == 10){
                v[i][j] = 1;
            }
        }
    }
        cnt++;
    for(int i = 3 ; i < cnt; i++){
        for(int j = 0 ; j < n ; j++){
            if(j == 1 || j == 4 || j == 6 || j == 8 ){
                v[i][j] = 1;
            }
        }
    }
        cnt++;
    for(int i =4 ; i < cnt; i++){
        for(int j = 0 ; j < n ; j++){
            if(j == 1 || j == 4 || j == 6 || j == 9 || j == 8 || j == 10){
                v[i][j] = 1;
            }
        }
    }
        cnt++;
    for(int i = 5 ; i < cnt; i++){
        
    }
        cnt++;
    for(int i = 6 ; i < cnt; i++){
        
    }
        cnt++;
    for(int i = 7 ; i < cnt; i++){
        for(int j = 0 ; j < n ; j++){
            if(j == 0 || j == 1 || j == 2 || j == 4 || j == 5 || j == 6 || j == 9 || j == 8 || j == 10 || j == 12){
                v[i][j] = 1;
            }
        }
    }
        cnt++;
    for(int i = 8; i < cnt; i++){
        for(int j = 0 ; j < n ; j++){
            if(j == 0  || j == 4 || j == 6 || j == 8 || j == 10 || j == 12){
                v[i][j] = 1;
            }
        }
    }
        cnt++;
    for(int i = 9; i < cnt; i++){
        for(int j = 0 ; j < n ; j++){
            if(j == 0 || j == 1 || j == 2 || j == 4 || j == 5 || j == 6 || j == 9 || j == 8 || j == 10 || j == 12){
                v[i][j] = 1;
            }
        }
    }
        cnt++;
    for(int i = 10 ; i < cnt; i++){
        for(int j = 0 ; j < n ; j++){
            if(j == 0  || j == 4 || j == 6 || j == 8 || j == 10 || j == 12){
                v[i][j] = 1;
            }
        }
    }
        cnt++;
    for(int i = 11; i < cnt; i++){
        for(int j = 0 ; j < n ; j++){
            if(j == 0 || j == 13 || j == 14 || j == 4 || j == 5 || j == 6 || j == 9 || j == 8 || j == 10 || j == 12){
                v[i][j] = 1;
            }
        }
    }
        cnt++;
    int l , r;
    cin >> l >> r;
    if(v[l][r]){
        cout << "IN" << sad;
    }
    else{
        cout << "OUT" << sad;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}