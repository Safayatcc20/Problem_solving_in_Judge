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
    long long n ;
    cin >> n;
    string s, t;
    cin >> s;
    t = s;
    map<char , long long>mp;
    for(long long i = 0 ; i < n ; i++){
        mp[s[i]]++;
    }
    char ch;
    bool f = false;
    long long ind = -1;
    for(long long i = 0 ; i < n ; i++){
        if(s[i] == s[i+1]) {
            mp[s[i]]--;
            continue;
        }
        mp[s[i]]--;
        for(long long j = 0 ; j < 26; j++){
            if(char('a'+ j) <= s[i]){
                if(mp[char('a' + j)]){
                    //cout << char('a' + j);
                    ch = char('a' + j);
                    f = true;
                    ind = i;
                    break;
                }
            }
        }
        if(f){
            break;
        }
        else {break;}
    }
    if(f){
        for(long long i = n-1; i > ind ; i--){
            if(s[i] == ch){
                s[i] = 'A';
                break;
            }
        }
        cout << ch ;
        for(long long i = 0 ; i < n ; i++){
            if(s[i] == 'A') continue;
            cout << s[i];
        }
        cout << sad;
    }
    else{
        cout << s << sad;
    }
    /* s = t;
    vector<string>vv;
    while(next_permutation(s.begin() , s.end())){
        string tt;
        for(long long i =  0 ; i < n ; i++){
            tt += s[i];
        }
        vv.push_back(tt);
    }
    sort(all(vv));
    for(long long i = 0 ; i < vv.size() ; i++){
        cout << vv[i] << sad;
    } */
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