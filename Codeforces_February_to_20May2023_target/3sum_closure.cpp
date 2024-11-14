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
    int n ;
    cin >> n;
    vector<long long>v , pos , neg;
    for(int i = 0 ; i < n ; i++){
        long long x;
        cin >> x;
        if(x < 0) neg.push_back(x);
        else if(x > 0) pos.push_back(x);
        else if(v.size() < 2){
            v.push_back(x);
        }
    }
    if(pos.size() > 2 || neg.size() > 2) {
        na;
        return;
    }
    v.insert(v.end(),  all(pos));
    v.insert(v.end(),  all(neg));
    n = v.size();
    for(int i = 0 ; i < n; i++){
        for(int j = i + 1; j < n  ; j++){
            for(int k = j + 1 ; k < n ; k++){
                bool f = true;
                for(int l = 0 ; l < n ; l++){
                    if(v[i] + v[j] + v[k] == v[l]){
                        f = false;
                    }
                }
                if(f){
                    na;
                    return;
                }
            }
        }
    }
    ha;
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