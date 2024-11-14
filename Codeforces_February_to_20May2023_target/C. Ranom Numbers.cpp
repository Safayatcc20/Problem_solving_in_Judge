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
int chk(char ch){
    if(ch == 'A') return 1;
    if(ch == 'B') return 10;
    if(ch == 'C') return 100;
    if(ch == 'D') return 1000;
    if(ch == 'E') return 10000;
}
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    char m = s[n-1];
    int sum = 0 ;
    vector<char>v(n);
    for(int i = n-1; i >= 0; i--){
        v[i] = m;
        m = max(s[i] , m);
    }
    int ind = 0 ;
    while(ind < n and s[ind] == 'E') ind++;
    bool f = false;
    if(ind != n){
        int in = ind;
        char ch = s[ind];
        for(int i = ind ; i < n ; i++){
            if(s[i] == 'E'){
                f = true ;
                break;
            }
            if(s[i] > ch){
                ch = s[i];
                in = i;
            }
        }
        if(f){
            s[in] ='E';
        }
    }
    if(!f and ind < n){
        int in = ind;
        char ch = s[ind];
        while(in < n and s[in] != v[in]){
            if(ch <  s[in]){
                ch = s[in];
                ind = in;
            }
            in++;
        }
        s[ind] = 'E';
    }
    for(int i = 0 ; i < n ;i++){
        if(s[i] < v[i]){
            sum -= chk(s[i]);
        }
        else{
            sum += chk(s[i]);
        }
    }
    cout << sum << sad;
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