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
    long long n , m;
    cin >> n >> m;
    long long cnt = 0 ;
    if(n == 1){
        long long k = 0 ;
        if(m == 1){
            cout << 0 << sad;
        }
        else cout << 2 << sad;
        for(long long i =0 ; i < m ; i++){
            cout << k << " ";
            k++;
        }
        cout << sad;
        return;
    }
    if(m == 1){
        cout <<  0 << sad;
        while(n--){
            cout << 0 << sad;
        }
        return;
    }
    vector<vector<long long>>v(n  , vector<long long>(m));
    if((n & 1 and m == n)){
        for(long long i = 0 ; i < m ; i++){
            int k = i; 
            for(long long j = 0 ; j < n -1; j++){
                v[j][i] = k;
                k++;
                if(k >= m) k = 0;
            }
        }
        cout << m << sad;
        for(long long i = 0 ; i < n - 1; i++){
            for(long long j = 0 ; j < m ; j++){
                cout << v[i][j] <<" ";
            }
            cout << sad;
        }
        for(long long i = 0 ; i < m ; i++){
            cout << i << " ";
        }
        cout << sad;
    }
    else if( !(n & 1) and n == m){
        for(long long i = 0 ; i < m ; i++){
            int k = i; 
            for(long long j = 0 ; j < n -1; j++){
                v[j][i] = k;
                k++;
                if(k >= m) k = 0;
            }
        }
        cout << m << sad;
        for(long long i = 0 ; i < n -1; i++){
            for(long long j = 0 ; j < m ; j++){
                cout << v[i][j] <<" ";
            }
            cout << sad;
        }
        for(long long i = 0 ; i < m ; i++){
            cout << i << " ";
        }
        cout << sad;
    }
    else if(!(n & 1) and m&1){
        //cout << 1 <<sad;
        for(long long i = 0 ; i < m ; i++){
            int k = i; 
            for(long long j = 0 ; j < min(m-1 , n); j++){
                v[j][i] = k;
                k++;
                if(k >= m) k = 0;
            }
        }
        if(m < n){
            long long print = n - m +1, ind = m;
            while(print - m + 1>= 0){
                print = print - m +1;
                for(long long i = 0; i < m ; i++){
                    int k = i;
                    int cnt = 0 ; 
                    for(long long j = ind-1; cnt < m-1; j++){
                        cnt++;
                        v[j][i] = k;
                        k++;
                        if(k >= m) k = 0;
                    }
                }
                //cout << print << " " << ind << sad;
                ind+= m-1;
            }
            if(print){
                for(long long i = 0 ; i < m ; i++){
                    int k = i;
                    int cnt = 0 ; 
                    for(long long j = ind-1; cnt < print; j++){
                        cnt++;
                        v[j][i] = k;
                        k++;
                        if(k >= m) k = 0;
                    }
                }
            }
        }
        if(n < m){
            cout << n + 1 << sad;
        }
        else{
            cout << m << sad;
        }
        for(long long i = 0 ; i < n; i++){
            for(long long j = 0 ; j < m ; j++){
                cout << v[i][j] <<" ";
            }
            cout << sad;
        }
    }
    else if(!(n & 1) and !(m&1)){
        //cout << 1 <<sad;
        for(long long i = 0 ; i < m ; i++){
            int k = i; 
            for(long long j = 0 ; j < min(m-1 , n); j++){
                v[j][i] = k;
                k++;
                if(k >= m) k = 0;
            }
        }
        if(m < n){
            long long print = n - m +1, ind = m;
            while(print - m + 1>= 0){
                print = print - m +1;
                for(long long i = 0; i < m ; i++){
                    int k = i;
                    int cnt = 0 ; 
                    for(long long j = ind-1; cnt < m-1; j++){
                        cnt++;
                        v[j][i] = k;
                        k++;
                        if(k >= m) k = 0;
                    }
                }
                //cout << print << " " << ind << sad;
                ind+= m-1;
            }
            if(print){
                for(long long i = 0 ; i < m ; i++){
                    int k = i;
                    int cnt = 0 ; 
                    for(long long j = ind-1; cnt < print; j++){
                        cnt++;
                        v[j][i] = k;
                        k++;
                        if(k >= m) k = 0;
                    }
                }
            }
        }
        if(n < m){
            cout << n + 1 << sad;
        }
        else{
            cout << m << sad;
        }
        for(long long i = 0 ; i < n; i++){
            for(long long j = 0 ; j < m ; j++){
                cout << v[i][j] <<" ";
            }
            cout << sad;
        }
    }
    else if((n & 1) and !(m&1)){
        //cout << 1 <<sad;
        for(long long i = 0 ; i < m ; i++){
            int k = i; 
            for(long long j = 0 ; j < min(m-1 , n); j++){
                v[j][i] = k;
                k++;
                if(k >= m) k = 0;
            }
        }
        if(m < n){
            long long print = n - m +1, ind = m;
            while(print - m + 1>= 0){
                print = print - m +1;
                for(long long i = 0; i < m ; i++){
                    int k = i;
                    int cnt = 0 ; 
                    for(long long j = ind-1; cnt < m-1; j++){
                        cnt++;
                        v[j][i] = k;
                        k++;
                        if(k >= m) k = 0;
                    }
                }
                //cout << print << " " << ind << sad;
                ind+= m-1;
            }
            if(print){
                for(long long i = 0 ; i < m ; i++){
                    int k = i;
                    int cnt = 0 ; 
                    for(long long j = ind-1; cnt < print; j++){
                        cnt++;
                        v[j][i] = k;
                        k++;
                        if(k >= m) k = 0;
                    }
                }
            }
        }
        if(n < m){
            cout << n + 1 << sad;
        }
        else{
            cout << m << sad;
        }
        for(long long i = 0 ; i < n; i++){
            for(long long j = 0 ; j < m ; j++){
                cout << v[i][j] <<" ";
            }
            cout << sad;
        }
    }
    else if((n & 1) and (m&1)){
        //cout << 1 <<sad;
        for(long long i = 0 ; i < m ; i++){
            int k = i; 
            for(long long j = 0 ; j < min(m-1 , n); j++){
                v[j][i] = k;
                k++;
                if(k >= m) k = 0;
            }
        }
        if(m < n){
            long long print = n - m +1, ind = m;
            while(print - m + 1>= 0){
                print = print - m +1;
                for(long long i = 0; i < m ; i++){
                    int k = i;
                    int cnt = 0 ; 
                    for(long long j = ind-1; cnt < m-1; j++){
                        cnt++;
                        v[j][i] = k;
                        k++;
                        if(k >= m) k = 0;
                    }
                }
                //cout << print << " " << ind << sad;
                ind+= m-1;
            }
            if(print){
                for(long long i = 0 ; i < m ; i++){
                    int k = i;
                    int cnt = 0 ; 
                    for(long long j = ind-1; cnt < print; j++){
                        cnt++;
                        v[j][i] = k;
                        k++;
                        if(k >= m) k = 0;
                    }
                }
            }
        }
        if(n < m){
            cout << n + 1 << sad;
        }
        else{
            cout << m << sad;
        }
        for(long long i = 0 ; i < n; i++){
            for(long long j = 0 ; j < m ; j++){
                cout << v[i][j] <<" ";
            }
            cout << sad;
        }
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