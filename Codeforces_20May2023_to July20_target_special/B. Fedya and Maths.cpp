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
int two(int n  ){//reming: function calling findXor(sending value - 1);
    int rest = n % 4;
    if(rest == 0) return 1;
    if(rest == 1) return 2;
    if(rest == 2) return 4;
    if(rest == 3) return 3;
}
int three(int n  ){//reming: function calling findXor(sending value - 1);
    int rest = n % 4;
    if(rest == 0) return 1;
    if(rest == 1) return 3;
    if(rest == 2) return 4;
    if(rest == 3) return 2;
}
void solve(){
    string s;
    cin >> s;
    int ans = 1 ,n = s[s.size()-1] - '0';
    if(n & 1){
        ans += 4;
    }
    else{
        ans += 1;
    }
    if(s.size() > 1) n  = (s[s.size()-2] - '0') * 10 + n;
    //cout << n << " " << ans << sad;
    ans += two(n);
    //cout << ans << sad;
    ans += three(n);
    //cout << ans << sad;
    cout << ans % 5 << sad;
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