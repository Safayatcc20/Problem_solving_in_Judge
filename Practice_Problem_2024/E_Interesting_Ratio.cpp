/***** Bismillahir Rahmanir Rahim *****/

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/// order_of_key(x) returns number of elements strictly less than x
/// find_by_order(x) return x th element of the set (0 based index)
/// less dile choto theke boro sajano
/// less equal dile multiset er moto kaj kore
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
const int N = 1e7 + 7;
vector<bool> is_prime(N + 1, true);
void sieve()
{
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime

    for (int i = 2; i * i <= N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        // for(int j = i +1; j <= n; j++){
        //     if(lcm(i,j) % gcd(i, j) == 0 and is_prime[lcm(i,j) / gcd(i, j)] ){
        //         cout << i << " "<< j << endl;
        //     }
        // }
        if (is_prime[i])
        {
            v.push_back(i);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = 0, r = v.size() - 1, chk = -1;
        while (l - 1 < r)
        {
            int mid = l + (r - l) / 2;
            if (v[mid] * i <= n)
            {
                chk = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        // cout << l << " "<< r << endl;
        if (chk != -1)
            ans += chk + 1;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    cin >> t;
    sieve();
    // for(auto x: pl){
    //     cout << x << " ";
    // }
    // cout << sad;
    // cout << pl.size() << sad;
    while (t--)
    {
        solve();
    }
}