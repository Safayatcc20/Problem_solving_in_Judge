 
 /***** Bismillahir Rahmanir Rahim *****/
 
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using oset = tree<T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
#define int long long
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
// Linear Diophantine Equation ax + by = c;
// if c % gcd( a , b)  == 0 then solution exist otherwise not
//solution by using  Extended Euclidean algorithm one solution
int extgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
// Euler totient function for single call
int phi(int n){
  int ans = n;
  for(int i = 2; i * i <= n ;i++){ 
   if(n % i == 0){
       ans /= i;
       ans *= (i-1);
       while(n % i== 0) n/= i;
   }
  }
  if(n > 1) ans /= n , ans *= (n - 1);
  return ans;
}
//Euler totient preprocessing(from 1 to n ) in O(nloglog(n))
vector<int>phai(1e7+10);
void init(){
// here check the problem requirement
     int maxn = 1e7+10;
     for(int i = 1; i <= maxn; i++){
       phai[i] = i;
     }
     for(int i = 2; i<= maxn; i++){
       if(phai[i] == i){
         for(int j = i; j <= maxn; j+=i){
           phai[j]/=i; phai[j] *= (i-1);
         }
       }
     }
     // here is the prefix sum of phai function
     // for(int i = 1; i <= maxn; i++){
     //     phai[i] += phai[i-1];
     // }
}

int printSpiralMatrix(int rows, int cols, vector<string> &matrix , int n , int m) {
    int top = rows, bottom = n-1, left = cols, right = m - 1;
    int value = 1;
    string ans="";
    int cnt =  0;
    while (top <= bottom && left <= right) {
        // Traverse top row
        for (int i = left; i <= right; ++i) {
            ans+=matrix[top][i] ;
        }
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; ++i) {
            ans+=matrix[i][right] ;
        }
        right--;

        // Traverse bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                ans+=matrix[bottom][i] ;
            }
            bottom--;
        }

        // Traverse left column
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                ans+=matrix[i][left] ;
            }
            left++;
        }
        cout <<ans << sad;
        ans+=ans;
        for (int j = 0; j < ans.size(); j++) {
            if (j + 3 < (int)ans.size() && ans[j] == '1' && ans[j+1] == '5' && ans[j+2] == '4' && ans[j+3] == '3') {
                cnt++;
            }
        }
        return cnt;
    }
}

void solve(){
    int n, m;
    cin >>n >> m;
    vector<string>v(n );
    vector<vector<bool>>vis(n , vector<bool>(m,false));
    for(int i = 0;i <n;i++){
        string s;
        cin >> s;
        v[i] = s;
    }
    // vector<int>layer(40005);
    // int count = 0 ;
    // for (int i = 0; (i + 1) * 2 <= n && (i + 1) * 2 <= m; ++i) {
    //     int pos = 0;
    //     for (int j = i; j < m - i; ++j) {
    //         cout << i << " "<< j << " ft " << v[i][j] << sad; 
    //         layer[pos++] = v[i][j];
    //     }
    //     for (int j = i + 1; j < n - i - 1; ++j) {
    //         cout << j << " "<< m-i-1 << " sec " << v[j][m-i-1] << sad;
    //         layer[pos++] = v[j][m - i - 1];}
    //     for (int j = m - i - 1; j >= i; --j) {
    //         cout << n-i -1 << " "<< j << " 3rd " << v[n-i-1][j] << sad;
    //         layer[pos++] = v[n - i - 1][j];
    //     }
    //     for (int j = n - i - 2; j >= i + 1; --j) {
    //         cout << j << " "<< i << " 4th " << v[j][i] << sad;
    //         layer[pos++] = v[j][i];
    //     }
    //     cout << sad;
    //     for (int j = 0; j < pos; ++j)
    //         if (layer[j] == '1' && layer[(j + 1) % pos] == '5' && layer[(j + 2) % pos] == '4' && layer[(j + 3) % pos] == '3')
    //             count++;
        
    // }
    int ans = 0 ;
    for(int i  = 0 ; i < n/2 ;i++){
        for(int j = 0; j < m/2;j++){
            ans+=printSpiralMatrix(i ,j, v , n , m);
        }
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