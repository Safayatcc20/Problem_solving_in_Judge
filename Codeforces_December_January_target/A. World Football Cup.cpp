/*
 **** Bismillahir Rahmanir Rahim ****
 */
 // unsolved
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
bool comp(pair<string , long long>&a , pair<string , long long>&b){
    return (a.second > b.second || a.second == b.second && a.first < b.first);
}
void solve(){
    long long n ;
    cin >> n;
    map<string , pair<long long, long long>>v;
    for(long long i = 0 ; i < n ; i++){
        string s;
        cin >> s;
        v[s].first = 0;
        v[s].second = 0;
    }
    long long cal = (n * (n - 1)) / 2;
    for(long long k = 0 ; k < cal; k++){
        string s;
        cin >> s;
        string num ;
        cin >> num;
        string make ;
        //cout << s << " " << num << sad;
        for(long long i = 0 ;  i < s.size(); i++){
            if(s[i] == '-'){
                int made = 0;
                for(long long j = 0; j < num.size() ; j++){
                    if(num[j] == ':'){
                        v[make].first += made;//goal dichi;
                        made = 0;
                    }
                    if(j == num.size()-1){
                        v[make].second += made;//goal khaichi
                    }
                    made+= num[j] - 48;
                }
                make = "";
            }
            if(i == s.size()-1){
                int made = 0;
                for(long long j = 0; j < num.size() ; j++){
                    if(num[j] == ':'){
                        v[make].second += made;//goal khaichi
                        made = 0;
                    }
                    if(j == num.size()-1){
                        v[make].first += made;// goal dichi
                    }
                    made+= num[j] - 48;
                }
            }
            make += s[i];
        }
    }
    vector<pair<string , long long>>vv(n+1);
    long long i = 0;
    for(auto &x:v){
        vv[i].first = x.first;
        vv[i].second = (x.second.first - x.second.second);
        i++;
    }
    sort(all(vv) , comp);
    for(long long i = 0 ; i <  n / 2 ; i++){
        cout << vv[i].first << sad;
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