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
    vector<vector<long long>>v, test ;
    vector<long long> chk;
    for(long long i = 0 ; i < n; i++ ){
        vector<long long>vv;
        for(long long j = 0 ; j < n ; j++){
            long long x ;
            cin >> x;
            vv.push_back(x);
        }
        v.push_back(vv);
    }
    for(long long i = 0 ; i < n ; i++){
        long long ans = 1;
        bool flag = true;
        for(long long j = 0 ; j < n  ; j++){
            if(j != i and flag){
                ans = gcd(v[i][j] , v[i][j+1]);
                j++;
                flag = false;
            }
            else if(j != i){
                ans = gcd(v[i][j] , ans); 
            }
        }
        chk.push_back(ans);
        //cout << ans << " ";
    }
    set<long long>s,ss;
    long long d ;
    for(auto &x:chk){
        d = x;
        break;
    }
    cout << d << sad;
    if(d == 1 ){
        for(long long i = 1; i < n-1;  i++){
            ss.insert(chk[i+1] / chk[i]);
        }
        if(ss.size() == 1){
            chk[0] = chk[2]/chk[1];
            for(long long i = 1; i < n ; i++){
                chk[i] /= chk[0];
            }
        }
        for(auto &x:chk) cout << x << " " ;
        cout << sad;
        return;
    }
    for(long long i = 0 ; i < n ; i++){
        vector<long long>vv;
        for(long long j = 0 ; j < n ; j++){
            if(j  == i){
                vv.push_back(0);
            }
            else{
                vv.push_back(chk[i]*chk[j]);
            }
        }
        test.push_back(vv);
    }
    bool flag = false;
    long long ind = -1;
    for(long long i = 0 ; i < n ; i++){
        for(long long j = 0 ; j < n ; j++){
            if(test[i][j] != v[i][j]){
                ind = i;
                flag =true;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    //for(auto &x:chk) cout << x << " " ;
    //cout << sad;
    for(auto &x:chk) {
        s.insert(x);
    }
    if(s.size() == 1){
        for(long long  i = 0 ; i < n ; i++){
            chk[i] = sqrt(chk[i]);
        }
        for(auto &x:chk) cout << x << " " ;
        cout << sad;
        return;
    }
    if(flag){
        for(long long i = 0 ; i < n-1; i++){
            if(gcd(chk[i] , chk[i+1]) > 1 and gcd(chk[i] , chk[i+1]) != chk[i] || ind == i){
                if(chk[i] < chk[i+1]){
                    chk[i+1] /= gcd(chk[i] , chk[i+1]);
                }
                else{
                    chk[i] /= gcd(chk[i] , chk[i+1]);
                }
                i++;
            }
        }
    }
    for(auto &x:chk) cout << x << " " ;
    cout << sad;
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