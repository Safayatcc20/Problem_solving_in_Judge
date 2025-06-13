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
         if (!it) break; 
         int cur_bit = (num >> i) & 1;
         int opposite = cur_bit ^ 1;
 
         if (it->next[opposite] && it->next[opposite]->cnt > 0)
         {
             ans |= (1LL << i);
             it = it->next[opposite];
         }
         else it = it->next[cur_bit]; 
     }
     return ans;
}
int query_min(int num)
{
    TrieNode *it = trie;
    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (!it) break;
        int cur_bit = (num >> i) & 1;

        // Try to go to the SAME bit first to minimize XOR
        int opposite = cur_bit ;
 
         if (it->next[cur_bit] && it->next[cur_bit]->cnt > 0)
         {
             it = it->next[cur_bit];
            }
        else{
            ans |= (1LL << i);
            it = it->next[opposite];
         }
    }
    return ans;
}

//Classical — remember sum! NICE!
// Count numbers in the trie that have XOR with x less than l
// x ^ y < l  => y < x ^ l 
//this concept also can use for counting the number of 
//subarray in the trie that have XOR of ai..aj less than l
int countXorLessThan(int x, int l) {
    TrieNode* it = trie;
    int count = 0;
    for (int i = 31; i >= 0; i--) {
        if (!it) break;

        int bit_x = (x >> i) & 1;
        int bit_l = (l >> i) & 1;

        int desired_bit = bit_x ^ 0;
        int opposite_bit = bit_x ^ 1;

        if (bit_l == 1) {
            if (it->next[desired_bit]) {
                count += it->next[desired_bit]->cnt;
            }
            it = it->next[opposite_bit];
        } else {
            it = it->next[desired_bit];
        }
    }
    return count;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //https://codeforces.com/contest/2093/problem/G
    // Maximum xor of subarray of two element
    // maximum subarray xor for a[l..r] where 1<= l <= r <= n
    // we can use a trie insert the value in trie and then
    // query the maximum xor for two element between l and r
    // by given already l to r-1 and add value a[r] in trie 
    // then query the maximum xor for the value a[l] to a[r]
    // and then remove the value a[l] from trie and add a[r+1] in trie
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
        vector<int> pre(n+1);
        for (int i = 0; i < n; i++)
        {
            pre[i+1] = pre[i] ^ v[i];
        }

        trie = new TrieNode();
        int best_subarray_xor =0;
        int res =0;
        insert(0);
        for (int i = 1; i <= n; i++)
        {
            int val = pre[i] ^ k;
            int chk = query(val);
            if(chk > res){
                res = chk;
                best_subarray_xor = res ^ k;
            }
            // cout << best_subarray_xor << " "<< res << sad;
            insert(pre[i]);
        }
        cout << best_subarray_xor << endl;
    }
}

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define sad '\n'
// #define all(x) x.begin(), x.end()

// class TrieNode {
// public:
//     TrieNode* next[2];
//     int cnt = 0;
//     TrieNode() {
//         for (int i = 0; i < 2; i++) {
//             next[i] = nullptr;
//         }
//         cnt = 0;
//     }
// };
// TrieNode* trie;

// void insert(int num) {
//     TrieNode* it = trie;
//     for (int i = 31; i >= 0; i--) {
//         int cur_bit = (num >> i) & 1;
//         if (it->next[cur_bit] == nullptr) {
//             it->next[cur_bit] = new TrieNode();
//         }
//         it = it->next[cur_bit];
//         it->cnt++;
//     }
// }

// pair<int, int> query(int num) {
//     TrieNode* it = trie;
//     int max_xor = 0;
//     int result_num = 0;
//     for (int i = 31; i >= 0; i--) {
//         if (!it) break;
//         int cur_bit = (num >> i) & 1;
//         int opposite = cur_bit ^ 1;
//         if (it->next[opposite] && it->next[opposite]->cnt > 0) {
//             max_xor |= (1LL << i);
//             result_num |= (opposite << i);
//             it = it->next[opposite];
//         } else {
//             result_num |= (cur_bit << i);
//             it = it->next[cur_bit];
//         }
//     }
//     return {max_xor, result_num};
// }

// int32_t main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
    
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, x;
//         cin >> n >> x;
//         vector<int> v(n);
//         for (int i = 0; i < n; i++) {
//             cin >> v[i];
//         }

//         // Compute prefix XORs
//         vector<int> prefix(n + 1, 0);
//         for (int i = 0; i < n; i++) {
//             prefix[i + 1] = prefix[i] ^ v[i];
//         }

//         // Initialize trie
//         trie = new TrieNode();
//         insert(0); // Insert prefix[0] = 0
//         int max_xor = 0;
//         int best_subarray_xor = 0;

//         // Process each prefix
//         for (int r = 0; r < n; r++) {
//             // Query max prefix[l] ^ (prefix[r+1] ^ x)
//             int target = prefix[r + 1] ^ x;
//             auto [current_xor, prefix_l] = query(target);
//             // Subarray XOR is prefix[r+1] ^ prefix[l]
//             int subarray_xor = prefix[r + 1] ^ prefix_l;
//             // Update if this gives a larger (subarray_xor ^ x)
//             if ((subarray_xor ^ x) > max_xor) {
//                 max_xor = subarray_xor ^ x;
//                 best_subarray_xor = subarray_xor;
//             }
//             // Insert prefix[r+1]
//             insert(prefix[r + 1]);
//         }

//         cout << best_subarray_xor << sad;

//         // Clean up trie
//         delete trie;
//     }
// }