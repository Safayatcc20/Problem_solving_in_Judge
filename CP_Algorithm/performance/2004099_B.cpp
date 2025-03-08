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
int n , cnt = 0;
void merge(vector<int>&v , int  l , int mid ,int r){
    vector<int>left, right;
    for(int i = 0; i < mid - l + 1; i++){
        left.push_back(v[l+i]);
    }
    for(int i = 0; i < r - mid ; i++){
        right.push_back(v[mid + 1 + i]);
    }
    int k = l , i , j;
    for(i = 0 , j  = 0 ; i < mid - l + 1 and j < r - mid; k++){
        if(left[i] <= right[j]){
            v[k] = left[i];
            i++;
        }
        else{
            v[k] = right[j];
            j++;
            cnt++;
        }
    }
    //cout << i << " " << j << sad;
    while(i < (mid - l + 1) ){
        v[k] = left[i];
        i++;
        k++;
    }
    while(j < r - mid  ){
        v[k] = right[j];
        k++ ; j++;
    }
}
void mergesort(vector<int>&v , int l , int r){
    if(l == r) return;
    //cout <<mid << sad;
    int mid = l + (r - l) / 2;
    mergesort(v , l , mid);
    mergesort(v , mid+ 1 , r);
    merge(v , l , mid , r);
}
void solve(){
    cin >> n;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    mergesort(v , 0 , n);
    cout << cnt << sad;
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