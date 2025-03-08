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
    long long n , k;
    cin >> n >> k;
    vector<long long>v;
    long long ans = 0;
    if(k > n){
        na;
        return;
    }
    if(n == k){
        ha;
        for(long long i = 1; i <= k; i++){
            cout << "1" << " " ;
        }
        cout << sad;
        return;
    }
    if((n - (k - 1)) & 1){
        ans = 0;
        for(long long i = 1; i < k ; i++){
            v.push_back(1);
            
        }
        v.push_back(n - (k -1));
        bool f= false;
        for(long long i = 0 ; i < v.size() ; i++){
            if(v[i] < 0 || v[i] % 2 == 0){
                f = true;
                break;
            }
        }
        if(f){
            f = false;
            v.clear();
            for(long long i = 1; i < k ; i++){
                v.push_back(2);
                v.push_back((n - 2*(k -1)) );
            }
            for(long long i = 0 ; i < v.size() ; i++){
                if(v[i] < 0 || v[i] % 2){
                    f = true;
                    break;
                }
            }
            if(f){
                na;
                return;
            }
            ha;
            for(long long i = 0 ; i < v.size() ; i++){
                cout << v[i] << " ";
            }
        }
        else {
            ha;
            for(long long i = 0 ; i < v.size() ; i++){
                cout << v[i] << " ";
            }
        }
    }
    else if(n -(2*(k-1)) > 0 and (n -(2*(k-1))) % 2 == 0 ){
        ans = 0;
        for(long long i = 1; i < k ; i++){
            v.push_back(2);
        }
        v.push_back((n - 2*(k -1)) );
        //cout << (n - 2*(k -1))  << sad;
        bool f = false;
        for(long long i = 0 ; i < v.size() ; i++){
            if(v[i] < 0 || v[i] % 2){
                f = true;
                break;
            }
        }
        if(f){
            f = false;
            v.clear();
            for(long long i = 1; i < k ; i++){
                v.push_back(1);
                
            }
            v.push_back(n - (k -1));
            for(long long i = 0 ; i < v.size() ; i++){
                if(v[i] < 0 || v[i] % 2 == 0){
                    f = true;
                    break;
                }
            }
            if(f){
                na;
                return;
            }
            ha;

            for(auto &x:v) cout << x <<" ";
        }
        else{

            ha;

            for(auto &x:v) cout << x <<" ";
        }
    }
    else{
        na;
        return;
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