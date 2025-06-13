 
 /***** Bismillahir Rahmanir Rahim *****/
 
 #include <bits/stdc++.h>
 using namespace std;
 #define sad '\n'
 #define all(b) b.begin(), b.end()
 #define ha cout << "YES" << '\n'
 #define na cout << "NO" << '\n'
 #define int long long
 long long t = 1;
 constexpr bool multiple_test_cases = 1;
 
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
         if(it->next[cur_bit] == NULL)
         {
             return;
         }
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
     if(ans <num) ans = num;
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
// Count numbers in the trie that have XOR with x less than l
// x ^ y < l  => y < x ^ l
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

void solve(){
     trie = new TrieNode();
     int n;
     cin >> n;
     while(n--){
         char ch ;
         cin >> ch;
         int x;
         cin >> x;
         if(ch == '1'){
             insert(x);
         }
         else if(ch == '2'){
             erase(x);
         }
         else{
            int l;
            cin >> l;
             //cout << query(x) << ' ';
            //cout << query_min(x) << ' ';
            cout << countXorLessThan(x , l) << '\n';
         }
     }
 }
 int32_t main()
 {
     ios_base::sync_with_stdio(0);
     cin.tie(nullptr)->sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     // long long t;
     //cin >> t;
     while (t--)
     {
         solve();
     }
 }