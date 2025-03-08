
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
// Euler totient preprocessing(from 1 to n ) in O(nloglog(n))
vector<int> phai(1e7 + 10);
void init()
{
    // here check the problem requirement
    int maxn = 1e7 + 10;
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
const double PI = acos(-1);

struct base
{
    double a, b;
    base(double a = 0, double b = 0) : a(a), b(b) {}
    const base operator+(const base &c) const { return base(a + c.a, b + c.b); }
    const base operator-(const base &c) const { return base(a - c.a, b - c.b); }
    const base operator*(const base &c) const { return base(a * c.a - b * c.b, a * c.b + b * c.a); }
    const base operator/(const double &k) const { return base(a / k, b / k); }
};

void fft(vector<base> &p, bool inv = false)
{
    int n = p.size(), i = 0;
    for (int j = 1; j < n - 1; j++)
    {
        for (int k = n >> 1; k > (i ^= k); k >>= 1)
            ;
        if (j < i)
            swap(p[i], p[j]);
    }
    for (int l = 1, m; (m = l << 1) <= n; l <<= 1)
    {
        double ang = 2 * PI / m;
        base wn = base(cos(ang), (inv ? 1.0 : -1.0) * sin(ang)), w;
        for (int i = 0, j, k; i < n; i += m)
        {
            for (w = base(1, 0), j = i, k = i + l; j < k; j++, w = w * wn)
            {
                base t = w * p[j + l];
                p[j + l] = p[j] - t;
                p[j] = p[j] + t;
            }
        }
    }
    if (inv)
        for (int i = 0; i < n; i++)
            p[i] = p[i] / n;
}

vector<int> multiply(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size(), sz = 1, tt = n + m - 1;
    while (sz < tt)
        sz <<= 1;
    vector<base> x(sz), y(sz), z(sz);
    for (int i = 0; i < n; i++)
        x[i] = base(a[i], 0);
    for (int i = 0; i < m; i++)
        y[i] = base(b[i], 0);
    fft(x), fft(y);
    for (int i = 0; i < sz; i++)
        z[i] = x[i] * y[i];
    fft(z, true);
    vector<int> ans(tt);
    for (int i = 0; i < tt; i++)
        ans[i] = llround(z[i].a);
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    int mx = 0;
    vector<int> v(n + 1), vv(n + 1);
    for (auto &x : v)
    {
        cin >> x;
        mx = max(x, mx);
    }
    for (auto &x : vv)
    {
        cin >> x;
        mx = max(x, mx);
    }
    vector<int> a(mx + 1), b(mx + 1);// mx <= 1e6 exist
    int k = mx;
    for(auto &x:v) a[x] = 1;
    for(auto &x:vv) b[k - x] = 1;
    // solve using fft
    // for all possible (a-b)
    // we need to set a value of k for b array
    // where b at  least max value of b element
    
    vector<int> ans = multiply(a, b);
    for (int i = 0; i < ans.size(); i++)
        cout << i - k << "  "<< ans[i] << sad;
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