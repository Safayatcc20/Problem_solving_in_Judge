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
bool test(long long mid, long long n){
    long long four = 0 , seven = 0;
    while(mid > 0){
        if(mid % 10 == 4) four++;
        if(mid % 10 == 7) seven++;
        mid /= 10;
    }
    if(four == seven){
        //cout << n << sad;
        return true;
    }
    if(mid >= n) return true;
    return false;
}
void solve(){
    long long n;
    cin >> n;
    bool flag = true;
    long long j = 0 , four = 0 , take = n , seven = 0 ;
    vector<long long>v;
    for(; n > 0; j++){
        //v.push_back(n % 10);
        if(n % 10 == 4) four++; 
        else if(n % 10 == 7) seven++; 
        else {flag = false;;}
        n /= 10;
    }
    //cout << v.size() << sad << i ;
    n = take;
    if(four == seven and flag){
        cout << take << sad;
        return ;
    }
    vector<long long>vv;
    long long num = 0 ;
    if(j & 1) j++;
    for(long long i = 0 ; i < j/2; i++){
        v.push_back(4);
        num = num * 10 + 4;
    }
    for(long long i = j / 2; i < j; i++){
        v.push_back(7);
        num = num * 10 + 7;
    }
    vv.push_back(num);
    while(next_permutation(all(v))){
        num = 0 ;
        for(long long i = 0 ; i < j; i++){
            num = num * 10 + v[i];
        }
        vv.push_back(num);
    }
    for(long long i = 0 ; i < vv.size() ; i++){
        if(vv[i] > n){
            cout << vv[i] << sad;
            return;
        }
    }
    vv.clear();
    v.clear();
    num = 0 ;
    j += 2;
    for(long long i = 0 ; i < j/2; i++){
        v.push_back(4);
        num = num * 10 + 4;
    }
    for(long long i = j / 2; i < j; i++){
        v.push_back(7);
        num = num * 10 + 7;
    }
    vv.push_back(num);
    while(next_permutation(all(v))){
        num = 0 ;
        for(long long i = 0 ; i < j; i++){
            num = num * 10 + v[i];
        }
        vv.push_back(num);
    }
    for(long long i = 0 ; i < vv.size() ; i++){
        if(vv[i] > n){
            cout << vv[i] << sad;
            return;
        }
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