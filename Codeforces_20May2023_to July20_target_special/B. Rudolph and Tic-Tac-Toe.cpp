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
    vector<string>v(3);
    for(int i = 0 ; i < 3; i++){
        string s;
        cin >> s;
        v[i] = s;
    }
    int n = 3;
    if(v[0][0] != '.' and v[0][0] == v[0][1] and v[0][0] == v[0][2]){
        cout << v[0][0] << sad;
    }
    else if(v[0][0] != '.' and v[0][0] == v[1][1] and v[0][0] == v[2][2]){
        cout << v[0][0] << sad;
    }
    else if(v[0][0] != '.' and v[0][0] == v[1][0] and v[0][0] == v[2][0]){
        cout << v[0][0] << sad;
    }
    else if(v[0][1] != '.' and v[0][1] == v[1][1] and v[0][1] == v[2][1]){
        cout << v[0][1] << sad;
    }
    else if(v[0][2] != '.' and v[0][2] == v[1][2] and v[0][2] == v[2][2]){
        cout << v[0][2] << sad;
    }
    else if(v[0][2] != '.' and v[0][2] == v[1][1] and v[0][2] == v[2][0]){
        cout << v[0][2] << sad;
    }
    else if(v[1][0] != '.' and v[1][0] == v[1][1] and v[1][0] == v[1][2]){
        cout << v[1][2] << sad;
    }
    else if(v[2][0] != '.' and v[2][0] == v[2][1] and v[2][0] == v[2][2]){
        cout << v[2][2] << sad;
    }
    else{
        cout << "DRAW" << sad;
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