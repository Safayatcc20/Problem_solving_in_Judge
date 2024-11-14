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
    string s;
    cin >> s;
    vector<char>v;
    int cnt  = 0;
    for(int i = 0 ; i < s.size() ; i++){
        v.push_back(s[i]);
        //cout << s[i] << sad;
        if(s[i] >= '5'){
            cnt++;
        }
    }
    if(s[0] >= '5'){
        cout << '1';
        for(auto &x:s) cout << 0 ;
        cout << sad;
        return;
    }
    if(cnt == s.size()){
        cout << 1;
        for(int i = 0; i < s.size() ; i++){
            cout << 0;
        }
        cout << sad;
    }
    else{
        int n = s.size(), index = -1;
        for(int i  = 0; i < n ; i++){
            if(s[i] >= '5'){
                index = i;
                break;
            }
        }
        if(index == -1){
            cout << s << sad;
            return;
        }
        for(int i = index-1; i>= 0 ; i--){
            if(s[i] == '9'){
               // s[i] = '0';
                index = i;
                continue;
            }
            else{
                s[i] = s[i] - '0'+'1';
                //cout << "ME " << s[i] << sad;
                if(s[i] <= '4'){
                    break;
                }
                else{
                    index = i;
                }
            }
        }
        //cout << index << sad;
        if(s[0] >= '5'){
            cout << 1 ;
            s[0] = '0';
        }
        for(int i = 0 ; i < index ; i++) {
            cout << s[i];
        }
        for(int i = index ; i < n; i++) cout << 0;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
}