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
    int n ,  m;
    cin >> n >> m;
    vector<int>ind(m+1, 0);
    vector<vector<char>>v(n+1 , vector<char>(m+1));
    bool f = false;
    for(int i = 1; i <= n ; i++){
        int ff = 0 ;
        for(int j = 1 ;j <= m ; j++){
            char ch;
            cin >> ch;
            if(ch == '.') v[i][j] = '.';
            else if(ch== 'L'){
                    if(ind[j] == 0) v[i][j] = 'W';
                    else v[i][j] = 'B';
                    ind[j] ^= 1;
            }
            else if(ch == 'R'){
                if(v[i][j-1] == 'W') v[i][j] = 'B';
                else v[i][j] = 'W';
                
            }
            else if(ch == 'U'){
                if(ff == 0) v[i][j] = 'W';
                else v[i][j] = 'B';
                ff^=1; 
            }
            else if(ch == 'D'){
                if(v[i-1][j] == 'W') v[i][j] = 'B';
                else v[i][j] = 'W';
            }
        }
        if(t) f = true;
    }
    for(int i = 1; i <= m ;i++){
        if(ind[i]) f = true;
    }
    if(f){
        cout << -1 << sad;
        return;
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= m ; j++){
            cout << v[i][j];
        }
        cout << sad;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}