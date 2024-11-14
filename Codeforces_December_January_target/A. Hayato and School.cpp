/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
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
    long long n , sum = 0 , cnt = 0;
    cin >> n ;
    vector<long long>v , v1;
    for(long long i = 1;  i<= n ; i++){
        long long x ;
        cin >> x;
        if(x & 1){
            v.push_back(i);
        }
        else{
            v1.push_back(i);
        }
    }
    if(v.size() >= 3){
        ha;
        cout << v[0] <<  " " << v[1] << " " << v[2] << sad;
    }
    else if(v1.size() >= 2 and v.size() >= 1){
        ha;
        cout << v1[0] <<" " << v1[1] <<" " << v[0] <<'\n';
		return;
	}
    else{
        na;
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