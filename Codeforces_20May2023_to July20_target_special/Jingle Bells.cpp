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
    int n;
    cin >> n;
    vector<int>v(22);
    int j = 6;
    for(int i = 1 ; i<= 21; i+=2){
        v[i] = j;
        j++;
    }
    for(int i = 0 ; i < v[n]; i++){
        for(int j = i; j < v[n]-1; j++){
            cout << " ";
        }
        for(int k = 0 ; k < (i+1) * 2 - 1; k++)
        {
            cout << "*";
        }
        cout << sad;
    }
    j = v[n] * 2 - 1 - n ;
    j /= 2;
    for(int i = 0;i < 5; i++ ){
        for(int k = 0; k < j ;k++) cout << " " ;
        for(int k = j; k < j + n;k++) cout << "*" ;
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