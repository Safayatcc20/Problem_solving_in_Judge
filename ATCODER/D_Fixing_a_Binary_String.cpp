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
long long findXor(long long n)
{ // reming: function calling findXor(sending value - 1);
    long long rest = n % 4;
    if (rest == 0)
        return n;
    if (rest == 1)
        return 1;
    if (rest == 2)
        return n + 1;
    if (rest == 3)
        return 0;
}
// Linear Diophantine Equation ax + by = c;
// solution by using  Extended Euclidean algorithm one solution
int extgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
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
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    int l = 0, r = n - 1;
    while (l < r - 1)
    {
        bool f = true;
        int mid = l + (r - l) / 2;
        int ind = n, cnt = k, j = mid;
        for (int i = mid + 1;  i < n and cnt; i++, cnt--)
        {
            if(i+k <n and s[i] == s[i+k+1]){
                f = false;
                break;
            }
            else if(i + k >= n){
                if(s[i] == s[j]){
                    f = false;
                    break;
                }
                j--;
            }
        }
        //cout << mid << " " << cnt << sad;
        if (f)
        {
            cout << mid << sad;
            return;
        }
        if(cnt){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    bool f = true;
    int ind = n, cnt = k, j = l;
    for (int i = l + 1; i < n and cnt; i++, cnt--)
    {

        if(i+k <n and s[i] == s[i+k+1]){
                f = false;
                break;
            }
            else if(i + k >= n){
                if(s[i] == s[j]){
                    f = false;
                    break;
                }
                j--;
            }
    }
    if (f)
    {
        cout << l << sad;
        return;
    }
    f = true;
    ind = n, cnt = k, j = r;
    for (int i = r + 1; i < n and cnt; i++, cnt--)
    {
        if(i+k <n and s[i] == s[i+k+1]){
                f = false;
                break;
            }
            else if(i + k >= n){
                if(s[i] == s[j]){
                    f = false;
                    break;
                }
                j--;
            }
    }
    if (f)
    {
        cout << r << sad;
        return;
    }
    cout << -1 << sad;
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