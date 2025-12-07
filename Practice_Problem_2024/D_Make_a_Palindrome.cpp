
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
const int MAXN = 2e6;
// Video
// https://www.youtube.com/watch?v=DPiY9wFxGIw&list=PLauivoElc3gilwo3g_ASRqysDvybOlzVQ&index=2
//  BIT(Fenwick Tree) for range counting
//  There is a trick when we need to use inversion concept
//  we use the value as a Index at this time if the value is
//  a[i] = 1e9 we set value equal to  1e4 = 1 , 1e8 = 2 , 1e9 = 4 like this way
//  reason is total array size never 10^5
//  map<int , int>mp; mp[1e4] =  1, mp[1e8] = 2 ,mp[1e9]  = 3
int BIT[MAXN];

// Update BIT at index idx
// Here we are updating by adding the value of index i
// also including range such as
// 13 is include 14, 16
void update(int idx, int value, int n)
{
    while (idx <= n)
    {
        BIT[idx] += value;
        idx += idx & -idx;
        // here we update also the including part of idx
        // 1101(13){13-13} -> 1101+0001 = 1110(14){13-14} -> 1110+0010= 10000(16){1-16} so on
        //{i - j} define which range capture here
    }
}

// Query BIT for sum of (1 to i'th) index
int query(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += BIT[idx];
        idx -= idx & -idx;
        // here we cover the index from 1 to i
        // 1101(13){13-13} -> 1101 -( 1101 & 0001) = 1100(12){13-14}
        // 1100(12){9-12} -> 1100- (1100 & 0100)= 1000(8){1-8}
        // 1000(8){1-8} -> 1000 - (1000 & 1000)= 0000(0)
    }
    return sum;
}
// Range Update and Point Query
void range_add(int l, int r, int val, int n)
{
    update(l, val, n);
    update(r + 1, -val, n);
}
int rangeSum(int l, int r)
{
    return query(r) - query(l - 1);
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    int ans = 0;

    if (k == 1)
    {
        ha;
        return;
    }
    bool f = false;
    for (int i = 0, j = n - 1; i <= j; i++, j--)
    {
        if (v[i] != v[j])
        {
            f = true;
            break;
        }
    }
    if (!f)
    {
        ha;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        update(v[i], 1, n);
    }
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (v[l] == v[r])
        {
            l++, r--;
            continue;
        }

        int left = query(v[l]);
        int right = query(v[r]);
        if (left < k and right < k)
        {
            na;
            return;
        }
        if (left >= k)
        {
            if (right < k)
                update(v[l], -1, n), l++;
            else if (v[l] > v[r])
                update(v[l], -1, n), l++;
            else
            {
                update(v[r], -1, n), r--;
            }
        }
        else
        {
            update(v[r], -1, n);
            r--;
        }
    }
    ha;
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