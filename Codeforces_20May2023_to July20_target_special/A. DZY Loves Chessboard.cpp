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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n , vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    for(int i = 0 ; i < 1 ; i++){
        for(int j = 0 ; j < m ;j++){
            if(j &  1 and v[i][j] == '.') cout << 'W';
            else if(v[i][j] == '.') cout << 'B';
            else cout << v[i][j];
        }
        cout << sad;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            //cout << v[i][j];
            if(v[i][j] == '.'){
                if((j-1 >= 0 && v[i][j-1] == 'B') || (j+1 < m && v[i][j+1] == 'B') ||  
                   (i+1 < n && v[i+1][j] == 'B') || (i-1 >= 0 && v[i-1][j] == 'B')){
                    cout << "W";
                    v[i][j] = 'W';
                }
                else{
                    v[i][j] = 'B';
                    cout << "B" ;
                }
            }
            else{
                cout << v[i][j] ;
            }
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
    //cin >> t;
    while (t--)
    {
        solve();
    }
}