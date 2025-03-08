
/***** Bismillahir Rahmanir Rahim *****/

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
// if c % gcd( a , b)  == 0 then solution exist otherwise not
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
// Euler totient function for single call
int phi(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans /= i;
            ans *= (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        ans /= n, ans *= (n - 1);
    return ans;
}
// Euler totient preprocessing for all value
vector<int> phai(1e6 + 4);
void init()
{
    // here check the problem requirement
    int maxn = 1e4 + 10;
    for (int i = 1; i <= maxn; i++)
    {
        phai[i] = i;
    }
    for (int i = 2; i <= maxn; i++)
    {
        if (phai[i] == i)
        {
            for (int j = i; j <= maxn; j += i)
            {
                phai[j] /= i;
                phai[j] *= (i - 1);
            }
        }
    }
    // here is the prefix sum of phai function
    // for(int i = 1; i <= maxn; i++){
    //     phai[i] += phai[i-1];
    // }
}
using cd = complex<double>;
const double PI = acos(-1);
vector<cd> fft(vector<cd> p, int n)
{
    if (n == 1)
        return p;
    vector<cd> pa, pb;
    for (int i = 0; i * 2 < n; i++)
    {
        pa.push_back(p[2 * i]);
        pb.push_back(p[2 * i + 1]);
    }
    pa = fft(pa, n / 2);
    pb = fft(pb, n / 2);
    double ang = (2 * PI) / n;
    cd w(1), w_delta(cos(ang), sin(ang));
    for (int i = 0; i * 2 < n; i++)
    {
        p[i] = pa[i] + w * pb[i];
        p[i + n / 2] = pa[i] - w * pb[i];
        w *= w_delta;
    }
    return p;
}
vector<cd> inversefft(vector<cd> p, int n)
{
    if (n == 1)
        return p;
    vector<cd> pa, pb;
    for (int i = 0; i * 2 < n; i++)
    {
        pa.push_back(p[2 * i]);
        pb.push_back(p[2 * i + 1]);
    }
    pa = inversefft(pa, n / 2);
    pb = inversefft(pb, n / 2);
    double ang = (-2 * PI) / n;
    cd w(1), w_delta(cos(ang), sin(ang));
    for (int i = 0; i * 2 < n; i++)
    {
        p[i] = pa[i] + w * pb[i];
        p[i + n / 2] = pa[i] - w * pb[i];
        w *= w_delta;
    }
    return p;
}
// fft and inverse fft in one function
void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
vector<int> multiply(vector<int> &a, vector<int> &b)
{
    vector<cd> fa, fb;
    fa.assign(a.begin(), a.end());
    fb.assign(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    // cout << n << sad;
    //  for(int i = 0 ; i < n; i++) {
    //      cout << fa[i] << " "<< fb[i] << sad;
    //  }
    fa.resize(n), fb.resize(n);
    // fa = fft(fa, n);
    // fb = fft(fb, n);
    fft(fa , false); // using void fft in comment
    fft(fb , false);
    // for(int i = 0 ; i < n; i++) {
    //     cout << fa[i] << " "<< fb[i] << sad;
    // }
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    // fa = inversefft(fa, n);
    fft(fa , true);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        // ans[i] = round(fa[i].real() / n);
        ans[i] = round(fa[i].real());
        // if use void fft then ans[i] = round(fa[i].real()); is right
    }
    // a.size() + b.size() - 1 is the new size of polynomial when multiply
    ans.resize(a.size() + b.size() - 1);
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    // solve using fft
    vector<int> ans = multiply(a, b);
    for (int i = 0; i <= 2 * n; i++)
        cout << ans[i] << " ";
    cout << sad;
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