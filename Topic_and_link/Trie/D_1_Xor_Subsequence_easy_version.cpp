#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sad '\n'
#define all(x) x.begin(), x.end()

class TrieNode {
public:
    TrieNode* next[2];
    int dpval[2];
    int cnt;

    TrieNode() {
        next[0] = next[1] = nullptr;
        dpval[0] = dpval[1] = 0;
        cnt = 0;
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
    void insert(int num , int dp , int v)
    {
        TrieNode *it = trie;
        for (int j = 31; j >= 0; j--)
        {
            int bit = (num >> j) & 1;
            if (!it->next[bit]) it->next[bit] = new TrieNode();
            it = it->next[bit];
            it->cnt++;
            int val_bit = (v >> j) & 1;
            it->dpval[val_bit] = max(it->dpval[val_bit], dp);
        }
    }


    int query(int num, int dp, int i) {
        TrieNode* it = trie;
        int ans = dp;
        for (int j = 31; j >= 0; j--) {
            if (!it) break;
            int bit = (num >> j) & 1;
            int inv_bit = bit ^ 1;
            if (it->next[inv_bit])
                ans = max(ans, it->next[inv_bit]->dpval[(i >> j) & 1]);
            it = it->next[bit];
        }
        return ans;
    }

    void clear(TrieNode* node) {
        if (!node) return;
        clear(node->next[0]);
        clear(node->next[1]);
        delete node;
    }

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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Trie trie;
        vector<int> dp(n, 0); 
        for (int i = 0; i < n; i++)
        {
            int x = v[i] ^ i;
            dp[i] = trie.query(x, dp[i],i)+ 1 ;
            trie.insert(x , dp[i] , v[i]);
            
        }
        int ans = 0 ;
        for(int i = 0 ; i < n ;i++){
            ans = max(ans , dp[i]);
        }
        cout << ans << sad;
    }
}