#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sad '\n'

const int M = 20; // Number of bits (since 2^19 > 3·10^5)

class TrieNode {
public:
    TrieNode* next[2]; // Children for bits 0 and 1
    int d;             // Number of leaves in subtree

    TrieNode() {
        next[0] = next[1] = nullptr;
        d = 0;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void add(int num) {
        vector<pair<TrieNode*, int>> path; // Store (node, bit) pairs
        TrieNode* node = root;
        
        // Traverse and build the path
        for (int i =31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            path.push_back({node, bit}); // Store current node and bit
            // cout << node->next[0]<< " "<< node->next[1] << " " << bit << endl;
            if (!node->next[bit]) {
                node->next[bit] = new TrieNode();
            }
            node = node->next[bit];
        }
        // cout << "Good"<< endl;
        // Set leaf d
        node->d = 1;
        
        // Update d for all nodes in the path (bottom-up)
        for (int i = path.size() - 1; i >= 0; i--) {
            TrieNode* curr = path[i].first;
            // cout << curr->next[0]<< " "<< curr->next[1] << " " << curr->d << endl;
            curr->d = 0;
            if (curr->next[0]) curr->d += curr->next[0]->d;
            if (curr->next[1]) curr->d += curr->next[1]->d;
            // cout << curr->next[0]<< " update "<< curr->next[1] << " " << curr->d << endl;
        }
    }
    
    int get_mex(int num) {
        int mex = 0;
        TrieNode* node = root;
        
        for (int pos = 31; pos >= 0; pos--) {
            if (!node) break; // Remaining bits of mex are 0
            
            int mex_bit = 0; // Prefer mex bit to be 0 to minimize mex
            int xor_bit = (num >> pos) & 1;
            // Compute the bit we need in the trie (mex XOR num)
            int need_bit = mex_bit ^ xor_bit;
            
            int child_d = 0;
            TrieNode* child = nullptr;
            if (node->next[need_bit]) {
                child = node->next[need_bit];
                child_d = child->d;
            }
            
            // cout << pos << " " << mex<< " "<< need_bit << " " << mex_bit << " " << child_d<< " "<<xor_bit << endl;
            // If the path exists and subtree is complete, must use mex_bit = 1
            if (child && child_d == (1LL << pos)) {
                mex_bit = 1;
                need_bit = mex_bit ^ xor_bit;
                child = node->next[need_bit];
            }
            
            // Set the mex bit
            mex |= (mex_bit << pos);
            // cout << pos << " "<< mex << " "<< need_bit << " sesh " << mex_bit << " " << child_d << endl;
            
            // Move to the next node
            node = child;
        }
        
        return mex;
    }
};

int32_t main() {


    // https://codeforces.com/contest/842/submission/316075368
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Build trie
    Trie trie;
    for (int i = 0; i < n; i++) {
        trie.add(a[i]);
    }
    
    // Process queries
    int c = 0;
    while (m--) {
        int k;
        cin >> k;
        c ^= k;
        int mex = trie.get_mex(c);
        cout << mex << sad;
    }
}