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
    int a, b, c, d, k;
    cin >> a >> c >> b >> d >> k;
    int ans = 0;

    int difx = 0;
    if (a < 0 and b < 0)
    {
        difx = abs(a) - abs(b);
    }
    else if (a < 0 and b >= 0)
    {
        difx = abs(a - b);
    }
    else if (b < 0 and a >= 0)
    {
        difx = abs(b - a);
    }
    else
    {
        difx = abs(a - b);
    }
    int dify = 0;
    if (c < 0 and d < 0)
    {
        dify = abs(c) - abs(d);
    }
    else if (c < 0 and d >= 0)
    {
        dify = abs(c - d);
    }
    else if (d < 0 and c >= 0)
    {
        dify = abs(d - c);
    }
    else
    {
        dify = abs(c - d);
    }
    if (difx <= k and dify <= k)
    {
        cout << difx + dify << sad;
        return;
    }
   // cout << difx << " " << dify << sad;
    if (difx <= k)
    {
        ans +=difx;
        if (difx * k <= dify)
        {
            ans +=  difx * k;
            dify -= difx * k;
            if(dify <= k){
                ans += dify;
            }
            else ans += dify/k+dify;
            if(dify%k){
                ans++;
            }
        }
        else{
            ans += dify;
        }
        cout << ans << sad;
    }
    else if (dify <= k)
    {
        ans+=dify;
        if (dify * k <= difx)
        {
            ans +=  dify * k;
            dify -= dify * k;
            if(difx <= k){
                ans += difx;
            }
            else ans += difx/k+difx;
            if(difx%k){
                ans++;
            }
        }
        else{
            ans += difx;
        }
        cout << ans << sad;
    }
    else {
        int x = difx/k;
        int y = dify/k;

        if(difx <= dify){
            ans += difx+difx;
            dify-=difx;
            difx=0;
            //cout << ans << " "<<dify << " ";
            if(dify <= k){
                ans += dify;
                dify= 0; 
            }
            else ans += dify/k+dify;
            if(dify%k){
                ans++;
            }
        cout << ans <<sad;
        }
        else if(difx >= dify){
            ans += dify+dify;
            difx-=dify;
            difx=0;
            if(dify <= k){
                ans += difx;
                difx= 0; 
            }
            else ans += difx/k+difx;
            if(difx%k){
                ans++;
            }
        cout << ans << sad;
        }
    }
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