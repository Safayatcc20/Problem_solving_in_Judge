
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
#define MAXN 1000005 // Carefull when solving the problem

// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j < MAXN; j += i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
map<int, int> mp, mpp;
vector<int> getFactorization(int x)
{
    vector<int> ret;
    int pre = 1;
    while (x != 1)
    {
         ret.push_back(spf[x]);
        x = x / spf[x];
    }
     return ret;
}
void solve()
{
    int c, d;
    cin >> c >> d;
    vector<pair<string, int>> v(d - c + 1);
    bool f = false;
    int cntf = 0, cntb = 0, fb = 0;
    for (int i = 0; i < d - c + 1; i++)
    {
        cin >> v[i].first;
        if (v[i].first == "FizzBuzz"){
            cntf++, cntb++;
            fb++;
            f = true;
        }
        v[i].second = c + i;
        if (v[i].first == "Fizz")
            cntf++;
        if (v[i].first == "Buzz")
            cntb++;
    }
    // cout << cntf << " "<<cntb << " "<< f << sad;;
    int n = d - c + 1;
    int fft = 0, fsec = 0, fizz = 0;
    if (cntf > 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i].first == "Fizz")
            {
                if (fft == 0)
                {

                    fft = v[i].second;
                }
                else
                {
                    fsec = v[i].second;
                    break;
                }
            }
            else if (fft != 0 and v[i].first == "FizzBuzz")
            {
                fsec = v[i].second;
                break;
            }
            else if (fft == 0 and v[i].first == "FizzBuzz")
            {
                fft = v[i].second;
            }
        }
        if (fsec)
            fizz = fsec - fft;
        else
            fizz = fft;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i].first == "Fizz")
            {
                if (fft == 0)
                {

                    fft = v[i].second;
                    break;
                }
            }
            else if (fft == 0 and v[i].first == "FizzBuzz")
            {
                fft = v[i].second;
                break;
            }
        }
        if(fft ) fizz = fft;
        else fizz = d + 1;
    }
    int bft = 0, bsec = 0, buzz = 0;
    if (cntb > 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i].first == "Buzz")
            {
                if (bft == 0)
                    bft = v[i].second;
                else
                {
                    bsec = v[i].second;
                    break;
                }
            }
            else if (bft != 0 and v[i].first == "FizzBuzz")
            {
                bsec = v[i].second;
                break;
            }
            else if (bft == 0 and v[i].first == "FizzBuzz")
            {
                bft = v[i].second;
            }
        }
        if (bsec)
            buzz = bsec - bft;
        else
            buzz = bft;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i].first == "Buzz")
            {
                if (bft == 0)
                {

                    bft = v[i].second;
                    break;
                }
            }
            else if (bft == 0 and v[i].first == "FizzBuzz")
            {
                bft = v[i].second;
                break;
            }
            
        }
        if(bft) buzz = bft;
        else buzz = d + 2;
    }
    cout << fizz << " "<< buzz << sad;
    
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}