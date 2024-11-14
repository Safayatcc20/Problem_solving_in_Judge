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
    int n , m;
    cin >> n >> m;
    vector<string>v(n);
    for(auto &x:v){
        cin >> x;
    }
    map<int , int>mp;
    int k = -1;
    string s;
    bool f1 = true , f2 = true , f3 = true , f4 = true;
    char c1 = 'v' , c2 = 'i' , c3 = 'k' , c4 = 'a';
    for(int i = 0  ; i < n ; i++){
        
        for(int j = 0 ; j < m ;j++){
        //cout << v[i][j] << " ";
            if(v[i][j] == c1 and k < j and f1){
                mp[j] = 1;
                f1 = false;
                k = j;
            }
            else if(!f1 and v[i][j] == c2 and k < j and f2){
                mp[j] = 1;
                f2  = false;
                k = j;
            }
            else if(!f1 and !f2 and v[i][j] == c3 and k < j and f3){
                mp[j] = 1;
                f3 = false;
                k = j;
            }
            else if(!f1 and !f2 and !f3 and v[i][j] == c4 and k < j and f4){
                mp[j] = 1;
                f4  = false;
                k = j;
            }
        }
        //cout << sad;
    }
    if(!f1 and !f2 and !f3 and !f4){
        ha;
    }
    else na;
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