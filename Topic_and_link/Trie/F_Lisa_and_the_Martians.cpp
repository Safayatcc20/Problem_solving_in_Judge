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
    int ind = -1;

    TrieNode() {
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
    void insert(int num, int k , int i )
    {
        TrieNode *it = trie;
        for (int j = k; j >= 0; j--)
        {
            int bit = (num >> j) & 1;
            if (!it->next[bit]) it->next[bit] = new TrieNode();
            it = it->next[bit];
            it->ind = i;
        }
    }


    int query(int num, int &x, int &nj , int i , int k) {
        TrieNode* it = trie;
        int ans = 0;
        for (int j = k; j >= 0; j--) {
            if (!it) break;
            int bit = (num >> j) & 1;
            int inv_bit = bit ^ 1;
            if (it->next[bit]){
                ans |= (1ll<<j);
                x |= ((inv_bit) << j);
                it = it->next[bit];
            }
            else{
                it = it->next[inv_bit];
            }
            if(j == 0){
                nj = it->ind;
            }
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
        int n , k ;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Trie trie;
        trie.insert(v[0] , k - 1, 0);
        int ai = 0 , aj = 1 , x = 0;
        for(int i = 1; i < n ;i++){
            int best_x  = 0 , j = -1;
            int cal = trie.query(v[i] , best_x , j , i , k - 1);
            if(cal > ((v[ai] ^ x) &(v[aj] ^ x))){
                ai = i , aj = j, x = best_x;
            }
            trie.insert(v[i] , k - 1 , i);
        }

        cout << ai + 1<< " "<< aj+ 1 << " "<< x << sad;
    }
}