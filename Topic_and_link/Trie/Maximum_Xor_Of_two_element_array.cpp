#include<bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(x) x.begin(),x.end()

class TrieNode{
    public:
        TrieNode* next[2];
        TrieNode(){
            next[0] = NULL;
            next[1] = NULL;
        }
};

TrieNode* buildtrie(vector<int>&a){
    TrieNode* root = new TrieNode();
    for(int i=0;i<a.size();i++){
        TrieNode* curr = root;
        for(int j=31;j>=0;j--){
            int bit = (a[i]>>j)&1;
            if(curr->next[bit] == NULL){
                curr->next[bit] = new TrieNode();
            }
            curr = curr->next[bit];
        }
    }
    return root;
}
int helper(TrieNode* root , vector<int>&v){
    int res = 0 ;
    for(int i = 0 ; i < v.size() ; i++){
        TrieNode* curr = root;
        int currres = 0;
        for(int j = 31 ; j >= 0 ; j--){
            int bit = (v[i]>>j)&1;
            if(curr->next[!bit] != NULL){
                currres += (1<<j);
                curr = curr->next[!bit];
                // !bit because we want to maximize the xor value
                // so we need to move in inverse direction
                // means if bit is 0 then we need to go to 1 and vice versa 
            }
            else{
                curr = curr->next[bit];
            }
        }
        res = max(res , currres);
    }
    return res;
}

class Solution {
public:
    int findMaximumXOR(vector<int>& v) {
        TrieNode *root = buildtrie(v);
        int ans = helper(root , v);
        return ans;
    }
};
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
    int t = 1;
    //cin >> t;
    while (t--)
    {
        int n= 6;
        // cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        Solution a;
        int ans = a.findMaximumXOR(v);
        cout << ans << sad;
        
    }
}