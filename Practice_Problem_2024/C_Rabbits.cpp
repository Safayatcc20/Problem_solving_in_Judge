
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
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << n << " " << s << sad;
    if (n == 1 or n == 2)
    {
        ha;
        return;
    }
    if (n == 3)
    {
        if (s == "101")
            na;
        else
            ha;
        return;
    }
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            v.push_back(i);
    }
    int nn = v.size();
    if (nn == 0)
    {
        ha;
        return;
    }
    if (nn == 1)
    {
        if (v[0] == 0 or v[0] == n - 1)
        {
            ha;
        }
        else
            na;
        return;
    }
    bool f1 = false;
    bool f2 = false;
    // for(auto &x:v) cout << x << " ";
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (abs(v[i] - v[i + 1]) <= 2)
        {
            i++;
        }
        else if (v[i] == 0)
        {
            continue;
        }
        else
        {
            f1 = true;
            break;
        }
    }
    for (int i = nn - 1; i > 0; i--)
    {
        if (abs(v[i] - v[i - 1]) <= 2)
        {
            i--;
        }
        else if (v[i] == n - 1)
        {
            continue;
        }
        else
        {
            f2 = true;
            break;
        }
    }
    if (nn & 1)
    {
        bool f3 = false;
        bool f4 = false;
        if (v[0] == 0)
        {
            for (int i = 1; i < v.size() - 1; i++)
            {
                if (abs(v[i] - v[i + 1]) <= 2)
                {
                    i++;
                }
                else
                {
                    f3 = true;
                    break;
                }
            }
        }
        if (v[nn - 1] == n - 1)
        {
            for (int i = nn - 2; i > 0; i--)
            {
                if (abs(v[i] - v[i - 1]) <= 2)
                {
                    i--;
                }
                else
                {
                    f4 = true;
                    break;
                }
            }
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
    for (int i = 1; i <= t; i++)
    {
        cout << i << " ami " << sad;
        solve();
    }
}

/* 
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
	int n; cin >> n;
	string s; cin >> s;
	bool ok = true;
	bool curr = (s[0] == '1');
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			cnt++;
		if (i == 0)
			continue;
		if (s[i] == s[i-1] && s[i] == '0')
			curr = false;
		if (s[i] == s[i-1] && s[i] == '1') {
			if (curr && cnt % 2 == 1)
				ok = false;
			curr = true;
			cnt = 0;
		}
	}
	
	if (curr && cnt % 2 == 1 && s[n-1] == '1')
		ok = false;
		
	cout << (ok ? "YES" : "NO") << "\n";
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T;
	while (T--)
		solve();
} */