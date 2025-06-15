#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sad '\n'
#define all(x) x.begin(), x.end()

class TrieNode
{
public:
    TrieNode *next[2];
    int cnt = 0;
    TrieNode()
    {
        for (int i = 0; i < 2; i++)
        {
            next[i] = NULL;
        }
        cnt = 0;
    }
};
TrieNode *trie;

void insert(int num)
{
    TrieNode *it = trie;
    for (int i = 31; i >= 0; i--)
    {
        int cur_bit = (num >> i) & 1;
        if (it->next[cur_bit] == NULL)
        {
            it->next[cur_bit] = new TrieNode();
        }
        it = it->next[cur_bit];
        it->cnt++;
    }
}
void erase(int num)
{
    TrieNode *it = trie;
    for (int i = 31; i >= 0; i--)
    {
        int cur_bit = (num >> i) & 1;
        
        it = it->next[cur_bit];
        it->cnt--;
    }
}
int query(int num)
{
    TrieNode *it = trie;
    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        int cur_bit = (num >> i) & 1;
        int opposite = cur_bit ^ 1;
        if (it->next[opposite] && it->next[opposite]->cnt > 0)
        {
            ans |= (1 << i);
            it = it->next[opposite];
        }
        else
        {
            it = it->next[cur_bit];
        }
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // maximum subarray xor for a[l1..r1] + a[l2...r2] where 1<= l1 <= r1 < l2 <= r2 <= n
    // we can use a trie to store the prefix xor of the array and then query the maximum xor for the suffix of the array
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        trie = new TrieNode();
        vector<int> rmax(n + 1, 0); // suffix max xor
        int ans = n + 1;
        for (int i = 0, j = 0; i < n; i++)
        {
            insert(v[i]);
            while (j <= i and query(v[i]) >= k)
            {
                ans = min(ans, i - j + 1);
                erase(v[j]);
                j++;
            }
        }
        if (ans > n)
            ans = -1;
        cout << ans << endl;
    }
}