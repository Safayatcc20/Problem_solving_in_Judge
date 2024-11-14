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
void solve(){
    int l , r;
    cin >> l >> r;
    int a= 2 , b;
    if( l & 1){
        b = l-1;
    }
    else{
        b = l-2;
    }
    while(l <= a + b and a+b <= r){
        //cout << a<< " " << b << sad;
        if(gcd(a, b) != 1 and b != 0){
            cout << a << " "<< b << sad;
            return;
        }
        b+=2;
    }
    if(l == r and l & 1 ){
        for(int i = 3; i * i <= l ; i++){
            if(l % i == 0){
                if(gcd(i , l - i) != 1 and l - i != 0){
                    cout << i << " " << l - i << sad;
                    return;
                }
            }
        }
    }
    cout << -1 << sad;
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