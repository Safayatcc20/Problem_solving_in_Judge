
// solution using manacher's algorithm
/***** Bismillahir Rahmanir Rahim *****/

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
string preprocess(const string &s)
{
    string t = "#";
    for (char c : s)
    {
        t += c;
        t += "#";
    }
    return t;
}

int CountPalindrom(const string &s)
{

    string t = preprocess(s);
    int n = t.size();
    vector<int> P(n, 0);
    int center = 0, right = 0;

    int maxLen = 0, centerIndex = 0;

    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        int mirror = 2 * center - i;

        if (i < right)
            P[i] = min(right - i, P[mirror]);

        // Try to expand around i
        while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 &&
               t[i + P[i] + 1] == t[i - P[i] - 1])
        {
            ++P[i];
        }

        // Update center and right boundary
        if (i + P[i] > right)
        {
            center = i;
            right = i + P[i];
        }

        // Track the max
        if (P[i] > maxLen)
        {
            maxLen = P[i];
            centerIndex = i;
        }
        if (n & 1)
        {
            total += (P[i] + 1) / 2;
        }
        else
        {
            total += (P[i] + 2) / 2;
        }
    }

    // Extract the longest palindrome from the original string
    int start = (centerIndex - maxLen) / 2;
    return total;
}
// for odd length palindrome, p[i] = length of longest palindromic substring centered at i
// for even length palindrome, p[i] = length of longest palindromic substring centered between i and i+1
// the length of the longest palindromic substring is p[i] + 1 or p[i] + 2 depending on whether i is odd or even
// the number of palindromic substrings is (p[i] + 1) / 2 for odd length and (p[i] + 2) / 2 for even length
// total number of palidromic substr. count formula
// 1.total += (p[i] + 1) / 2 for odd length and
// 2.total += (p[i] + 2) / 2 for even length
// do it inside the for loop
void solve()
{
    string s;
    cin >> s;
    string ss="#";
    int ans = 0 ;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (s[i] == '-')
    //     {
    //         ss.pop_back();
    //         ss.pop_back();
    //     }
    //     else
    //     {
    //         ss.push_back(s[i]);
    //         ss.push_back('#');
    //     }
    //     ans =  CountPalindrom(ss);
    // }
    ans =  CountPalindrom(s);
    cout << ans << sad;
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