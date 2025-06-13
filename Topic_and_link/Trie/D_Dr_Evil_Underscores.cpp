#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sad '\n'
#define all(x) x.begin(), x.end()

class TrieNode
{
public:
    TrieNode *next[2];
    int dpval[2];
    int cnt;
    int ind = -1;
    vector<int>v;
    TrieNode()
    {
        next[0] = next[1] = nullptr;
        dpval[0] = dpval[1] = 0;
        cnt = 0;
        ind = -1;
    }
};

class Trie
{
    TrieNode *trie;

public:
    Trie()
    {
        trie = new TrieNode();
    }
    void insert(int num)
    {
        TrieNode *it = trie;
        for (int j = 30; j >= 0; j--)
        {
            int bit = (num >> j) & 1;
            if (!it->next[bit])
                it->next[bit] = new TrieNode();
            it = it->next[bit];
            it->cnt++;
        }
    }

    int query(int num)
    {
        TrieNode *it = trie;
        int ans = 0;
        for (int j = 30; j >= 0; j--)
        {
            if (!it)
                break;
            int bit = (num >> j) & 1;
            int inv_bit = bit ^ 1;
            if (it->next[bit] and it->next[bit]->cnt > 0)
            {
                it = it->next[bit];
            }
            else
            {
                ans |= (1ll << j);
                it = it->next[inv_bit];
            }
        }
        return ans;
    }

    void remove(int num)
    {
        TrieNode *it = trie;
        for (int j = 30; j >= 0; j--)
        {
            int bit = (num >> j) & 1;
            TrieNode *nxt = it->next[bit];
            if (!nxt)
                return; // already removed
            nxt->cnt--; // decrease count
            if (nxt->cnt == 0)
            {
                delete nxt;
                it->next[bit] = nullptr;
                return; // stop early once a path is deleted
            }
            it = nxt;
        }
    }
    void clear(TrieNode *node)
    {
        if (!node)
            return;
        clear(node->next[0]);
        clear(node->next[1]);
        delete node;
    }
    int dfs( int bit) {
            TrieNode *node = trie;
            if (!node || bit < 0) return 0;
            TrieNode* left = node->next[0];
            TrieNode* right = node->next[1];
            if (!left) return dfs( bit - 1);
            if (!right) return dfs( bit - 1);
            return (1 << bit) | min(dfs( bit - 1), dfs( bit - 1));
        }


    // int dfs(TrieNode* node, int level) {
    //     if (!node) return LLONG_MAX;
    //     if (!node->next[0] && !node->next[1]) return LLONG_MAX;

    //     if (node->next[0] && node->next[1]) {
    //         // Find minimal cross XOR
    //         TrieNode* L = node->next[0];
    //         TrieNode* R = node->next[1];

    //         int min_xor = LLONG_MAX;
    //         function<void(TrieNode*, TrieNode*, int)> search = [&](TrieNode* a, TrieNode* b, int lev) {
    //             if (!a || !b) return;
    //             if (lev < 0) {
    //                 for (int x : a->values)
    //                     for (int y : b->values)
    //                         min_xor = min(min_xor, x ^ y);
    //                 return;
    //             }

    //             for (int bt = 0; bt < 2; bt++)
    //                 search(a->next[bt], b->next[bt], lev - 1);
    //             for (int bt = 0; bt < 2; bt++)
    //                 search(a->next[bt], b->next[bt ^ 1], lev - 1);
    //         };

    //         search(L, R, level - 1);
    //         return min({ dfs(L, level - 1), dfs(R, level - 1), (1LL << level) + min_xor });
    //     }

    //     return dfs(node->next[0] ? node->next[0] : node->next[1], level - 1);
    // }
    ~Trie()
    {
        clear(trie);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // https://codeforces.com/contest/2093/problem/G
    //  Maximum xor of subarray of two element
    //  maximum subarray xor for a[l..r] where 1<= l <= r <= n
    //  we can use a trie insert the value in trie and then
    //  query the maximum xor for two element between l and r
    //  by given already l to r-1 and add value a[r] in trie
    //  then query the maximum xor for the value a[l] to a[r]
    //  and then remove the value a[l] from trie and add a[r+1] in trie
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> vv(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> vv[i];
        }
        Trie trie;
        for (int i = 0; i < n; i++)
        {
            trie.insert(vv[i]);
        }
        int ans = trie.dfs( 30);
    }
}