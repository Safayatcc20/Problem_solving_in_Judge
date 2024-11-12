
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
void solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &x : v)
        cin >> x;
    if(n<3){
        cout << n << sad;
        return;
    }
    string ans = "";
    ans += v[0][0];
    int j = 1;
    int con = 0, i = 0;
    if (v[0][0] != 'A' and v[0][0] != 'E' and v[0][0] != 'O' and v[0][0] != 'I' and v[0][0] != 'U' and v[0][0] != 'Y')
    {
        con++;
    }
    for (i = 0; i < 1; i++)
    {
        if (ans[j - 1] != 'A' and ans[j - 1] != 'E' and ans[j - 1] != 'O' and ans[j - 1] != 'I' and ans[j - 1] != 'U' and ans[j - 1] != 'Y')
        {
            if (v[i + 1][0] != 'A' and v[i + 1][0] != 'E' and v[i + 1][0] != 'O' and v[i + 1][0] != 'I' and v[i + 1][0] != 'U' and v[i + 1][0] != 'Y')
            {
                if (i + 2 < n)
                {
                    if (v[i + 2][0] != 'A' and v[i + 2][0] != 'E' and v[i + 2][0] != 'O' and v[i + 2][0] != 'I' and v[i + 2][0] != 'U' and v[i + 2][0] != 'Y')
                    {
                        if (v[i + 1].size() > 1)
                        {
                            if (v[i + 1][1] != 'A' and v[i + 1][1] != 'E' and v[i + 1][1] != 'O' and v[i + 1][1] != 'I' and v[i + 1][1] != 'U' and v[i + 1][1] != 'Y')
                            {
                                if (v[i].size() > 1 and v[i][1] != 'A' and v[i][1] != 'E' and v[i][1] != 'O' and v[i][1] != 'I' and v[i][1] != 'U' and v[i][1] != 'Y')
                                {
                                    cout << '*' << sad;
                                    return;
                                }
                                else if (v[i].size() > 1)
                                {
                                    ans += v[i][1];
                                    j++;
                                    con = 0;
                                }
                                else
                                {
                                    cout << "*" << sad;
                                    return;
                                }
                            }
                            else
                            {
                                ans += v[i + 1][0];
                                ans += v[i + 1][1];
                                j += 2;
                                i++;
                                con = 0;
                            }
                        }
                        else if (v[i].size() > 1 and v[i][1] != 'A' and v[i][1] != 'E' and v[i][1] != 'O' and v[i][1] != 'I' and v[i][1] != 'U' and v[i][1] != 'Y')
                        {
                            if (v[i].size() > 2 and v[i][2] != 'A' and v[i][2] != 'E' and v[i][2] != 'O' and v[i][2] != 'I' and v[i][2] != 'U' and v[i][2] != 'Y')
                            {
                                cout << '*' << sad;
                                return;
                            }
                            else if (v[i].size() > 2)
                            {
                                ans += v[i][1];
                                ans += v[i][2];
                                con = 0;
                                j += 2;
                            }
                            else
                            {
                                cout << "*" << sad;
                                return;
                            }
                        }
                        else if (v[i].size() > 1)
                        {
                            ans += v[i][1];
                            con = 0;
                            j++;
                        }
                        else
                        {
                            cout << "*" << sad;
                            return;
                        }
                    }
                    else
                    {
                        ans += v[i + 1][0];
                        ans += v[i + 2][0];
                        j += 2;
                        i += 2;
                        con = 0;
                    }
                }
                else
                {
                    ans += v[i + 1][0];
                    j++;
                    i++;
                    con++;
                }
            }
            else
            {
                ans += v[i + 1][0];
                j++;
                i++;
                con = 0;
            }
        }
    }
    //cout << i << " " << con << sad;
    for (; i < n; i++)
    {

        if (ans[j - 1] != 'A' and ans[j - 1] != 'E' and ans[j - 1] != 'O' and ans[j - 1] != 'I' and ans[j - 1] != 'U' and ans[j - 1] != 'Y')
        {
            if (v[i].size() > 1)
            {
                if (v[i][0] != 'A' and v[i][0] != 'E' and v[i][0] != 'O' and v[i][0] != 'I' and v[i][0] != 'U' and v[i][0] != 'Y')
                {
                    if (i + 1 < n)
                    {
                        if (v[i + 1][0] != 'A' and v[i + 1][0] != 'E' and v[i + 1][0] != 'O' and v[i + 1][0] != 'I' and v[i + 1][0] != 'U' and v[i + 1][0] != 'Y')
                        {
                            
                            if ( v[i][1] != 'A' and v[i][1] != 'E' and v[i][1] != 'O' and v[i][1] != 'I' and v[i][1] != 'U' and v[i][1] != 'Y')
                            {
                                cout << '*' << sad;
                                return;
                            }
                            else
                            {
                                ans += v[i][0];
                                ans+= v[i][1];
                                con = 0;
                                j += 2;
                            }
                        }
                        else
                        {
                            ans += v[i][0];
                            ans += v[i + 1][0];
                            j+=2;
                            i++;
                            con = 0;
                        }
                    }
                    else{
                        if(con == 2){
                            cout << "*"<< sad;
                            return;
                        }
                        else {
                            con++;
                            ans+=v[i][0];
                            j++;
                        }
                    }
                }
                else{
                    ans += v[i+1][0];
                    con = 0 ;
                }
            }
            else
            {
                if (v[i][0] != 'A' and v[i][0] != 'E' and v[i][0] != 'O' and v[i][0] != 'I' and v[i][0] != 'U' and v[i][0] != 'Y')
                {
                    if(con == 2){
                        cout << "*"<< sad;
                        return;
                    }
                    else {
                        con++;
                        ans+=v[i][0];
                        j++;
                    }
                }
                else{
                    ans+=v[i][0];
                    con = 0;
                }
            }
        }
        else
        {
            ans += v[i][0];

            j++;
            if (v[i][0] != 'A' and v[i][0] != 'E' and v[i][0] != 'O' and v[i][0] != 'I' and v[i][0] != 'U' and v[i][0] != 'Y')
                con++;
            else con = 0;
        }
    }
    //cout << ans << " ";
    cout << ans.size() << sad;
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