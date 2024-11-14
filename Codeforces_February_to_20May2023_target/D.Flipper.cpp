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
    long long n;
    cin >> n;
    vector<long long>v(n);
    vector<long long>result;
    long long ind = n+1;
    for(long long i = 0 ; i < n ; i++){
        cin >> v[i];
        if(v[i] == n){
            result.push_back(v[i]);
            ind = i;
        }
        else if(i > ind ){
            result.push_back(v[i]);
        }
    }
    
    if(n == 1){
        cout << 1 << sad;
        return;
    }
    long long j = 0;
    if(ind == 0){
        result.clear();
        ind = n;
        for(long long i = 0 ; i < n ; i++){
            if(v[i] == n-1){
                result.push_back(v[i]);
                ind = i;
            }
            else if(i > ind ){
                result.push_back(v[i]);
            }
        }
        if(ind == n - 1){
            j = ind - 1;
        }
        else{
            result.push_back(v[ind-1]);
            j = ind - 2;
        }
    }
    else if(ind == n -1){
        j = ind - 1;
    }
    else{
        result.push_back(v[ind-1]);
        j = ind - 2;
    }
        while(v[0] <= v[j] and j >= 0){
            result.push_back(v[j]);
            j--;
        }
        for(long long  i = 0 ; i <= j ; i++){
            result.push_back(v[i]);
        }
        for(long long i = 0 ; i < n ; i++){
            cout << result[i] << " ";
        }
        cout << sad;
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