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
    int  n ;
    cin >> n;
    string t;
    cin >> t;
    int sz = t.size();
    vector<int>ans;
    for(int i = 0 ; i < n ; i++){
        cin.ignore();
        string s;
        cin >> s;
        int k = 0 , cnt = 0 ;
        bool f= true;
        if(s == t) ans.push_back(i+1);
        else if(s.size() == sz ){
            for(int j = 0 ; j< s.size() ; j++){
                if(s[j] != t[k]){
                    cnt++;
                    k++;
                    if(cnt > 1){
                         f = false;
                    }
                }
                else k++;
            }
            if(f){
                ans.push_back(i+1);
            }
        }
        else if(sz - s.size() == 1){
            for(int j = 0 ; j< t.size() ; j++){
                if(s[j] != t[k]){
                    k++;
                    cnt++;j--;
                    if(cnt  > 1){
                        f = false;
                        break;
                    }
                }
                else {
                    k++;
                }
            }
            if(f){
                ans.push_back(i+1);
            }
        }
        else {
            for(int j = 0 ; j< s.size() ; j++){
                if(s[j] != t[k]){
                    cnt++;
                    if(cnt  > 1){
                        f = false;
                        break;
                    }
                }
                else {
                    k++;
                }
            }
            if(f){
                ans.push_back(i+1);
            }
        }
    }
    cout << ans.size() << sad;
    for(auto &x:ans) cout << x << " ";
    cout << endl;
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