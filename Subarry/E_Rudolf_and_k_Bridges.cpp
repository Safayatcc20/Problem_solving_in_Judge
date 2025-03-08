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
#define int long long
long long t = 1;
const int inf = 1e18;
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
    int n , m , k , d;
    cin >> n >> m >> k >> d;
    vector<int>val(n);
    for(int i = 0 ; i < n ; i++){
        vector<int>v(m);
        for(int j = 0 ; j < m ; j++){
            cin >> v[j];
            v[j]++;
        }
        vector<int>findminimum_row(m , 0);
        deque<int> dq;
        findminimum_row[0] = 1;
        /* Process first k (or first window)
        elements of array */
        int store;
        for ( store = 1; store < min(d + 1, m); ++store) {
    
            // For every element, the previous
            // smaller elements are useless so
            // remove them from dq
            while ((!dq.empty()) && findminimum_row[store-1] < findminimum_row[dq.back()])
    
                // Remove from rear
                dq.pop_back();
    
            // Add new element at rear of queue
            dq.push_back(store - 1);
            findminimum_row[store] = v[store] + findminimum_row[dq.front()]; 
        }
    
        // Process rest of the elements,
        // store.e., from arr[k] to arr[n-1]
        for (; store < m; ++store) {
    
            // The element at the front of
            // the queue is the largest element of
            // previous window, so print it
            
    
            // Remove the elements which
            // are out of this window
            while ((!dq.empty()) && abs(store -dq.front()) > d+ 1)
    
                // Remove from front of queue
                dq.pop_front();
    
            // Remove all elements
            // smaller than the currently
            // being added element (remove
            // useless elements)
            while ((!dq.empty()) && findminimum_row[store-1] < findminimum_row[dq.back()])
                dq.pop_back();
    
            // Add current element at the rear of dq
            dq.push_back(store- 1);
            findminimum_row[store] = v[store] + findminimum_row[dq.front()];
        }
        val[i] = findminimum_row[m-1];
    }
    int ans = 0 , sum = 0 ;
    for(int i = 0 ; i < k; i++){
        sum += val[i];
    }
    ans = sum;
    int j = 0 ;
    for(int i = k ; i < n ; i++){
        
        sum -= val[j];
        sum += val[i];
        j++;
        ans = min(ans , sum);
    }
    cout << ans << sad;
}
int32_t main()
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