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
bool isSetBit(int val, int pos)
{
    return (val & (1LL << pos)) != 0;
}

void setBit(int &val, int pos)
{
    val = (val | (1LL << pos));
}

void clearBit(int &val, int pos)
{
    val = (val & (~(1LL << pos)));
}

void printbin(int a)
{
    bitset<32> decimal(a);
    cout << decimal << '\n';
}

void printdeci(string a)
{
    bitset<32> deci(a);
    int x = deci.to_ulong();
    cout << x << '\n';
}
int findMSB(int num)
{
    if (num == 0)
        return -1; // No MSB if the number is zero
    int msbPos = 0;
    while (num > 1)
    {
        num >>= 1;
        msbPos++;
    }
    return msbPos;
}
// Count the number of trailing zeros in a binary number
int countTrailingZeros(int num)
{
    if (num == 0)
        return 32; // If num is zero, all bits are zero
    int count = 0;
    while ((num & 1) == 0)
    {
        num >>= 1;
        count++;
    }
    return count;
}
// Count the number of leading zeros in a binary number
int countLeadingZeros(int num)
{
    if (num == 0)
        return 32; // If num is zero, all bits are zero
    int count = 0;
    int bitLength = 31; // For a 32-bit integer
    while ((num & (1 << bitLength)) == 0)
    {
        count++;
        bitLength--;
    }
    return count;
}
void solve()
{
    int n, x;
    cin >> n >> x;
    if (n == 1)
    {
        cout << x << sad;
        return;
    }
    if (n == 2)
    {
        cout << 0 << " " << x << sad;
        return;
    }
    if( n >= x){
        for(int i = 0; i <= min(n -1, x); i++){
            cout << i << " ";
        }
        n-=x+1;
        int cnt = 0;
        while(n>0){
            n--;
            cout << cnt << " ";
            cnt++;
            if(cnt > x){
                cnt = 0 ;
            }
        }
        cout << sad;
        return;
    }
    vector<int> v;
    for (int i = 0; i < 30; i++)
    {
        int a = (1 << i);
        if (a & x)
        {
            v.push_back(a);
        }
    }
    n--;
    vector<int> ans;
    ans.push_back(0);
    for (auto &i : v)
    {
        //  cout << i << sad;
        int p = i;
        int q = p * 2;
        while (n > 0 and p < q and p <= x)
        {
            //  cout << p << " ";
            if ((p & (~x)) == 0)
                ans.push_back(p), n--;
            p++;
        }
        if (n == 0)
        {
            break;
        }
    }
    int sum = 0;
    for (auto &m : ans)
    {
        sum |= m;
        // cout << i << " ";
    }
    if (sum != x)
    {
        // cout << sum << " "<< n  << " "<< ans.size()<< sad;
        if(n == 0){
            n++;
            sum^= ans[ans.size()-1];
            ans[ans.size()-1] = 0;
            for(int i = 0  ; i < ans.size()-1; i++){
                cout << ans[i] << " ";
            }
        }
        else{
            for(int i = 0  ; i < ans.size(); i++){
                cout << ans[i] << " ";
            }
        }
        // cout << sum << " "<< n  << " "<< ans.size()<< sad;
        for(int i = 0; i <= x;i++){
            
            if(((sum|i) == x)){
                // cout << i << " hi ";
                // n--;
                sum =i;
                break;
            }
        }
        while (n--)
        {
            cout << sum << " ";
        }
        
    }
    else
    {
        for(int i = 0  ; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        while (n--)
        {
            cout << 0 << " ";
        }
    }
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