
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
void decrypt(int row , int col , string &key , map<int , pair<char, int>>&mp,vector<vector<char>> &v, string &cipher )
{
    map<char , vector<char>>smp;
    string nkey = key;
    int k = 0;
    int len = cipher.size();
    // cout << cipher << endl;
    for(int i = 0 ;i < col; i++){
        for(int j =1; j  < row ;j++){
            smp[key[i]].push_back(cipher[k]);
            // cout << cipher[k] << " ";
            k++;
        }
    }
    // cout << endl;

    // for(auto &x:smp){
    //     cout << x.first << " : ";
    //     for(int i = 0 ; i<  x.second.size(); i++){
    //         cout << x.second[i];
    //     }
    //     cout<< endl;
    // }
    // cout << endl;
    int kk = 0 ;
    for(int i = 0 ; i < row -1 ; i++){
        for(int j= 0; j < col; j++){
            if(smp[key[j]][kk] == '*') continue;
            cout << smp[key[j]][kk];
        }
        kk++;
    }
    cout << endl;
}

void solve()
{
    string plain, key;
    cin >> plain >> key;
    int col = key.size();
    int row = plain.size();
    row = (col + row - 1) / col;
    row++;
    //  cout  << col << " "<< row << endl;
    vector<vector<char>> v(row, vector<char>(col));
    
    int k = 0;
    for(int i = 0 ;i< row; i++){
        // cout <<  i << " ";
        for(int j = 0 ;j < col; j++){
            if(i == 0){
                v[i][j] = key[j];
            }
            else{
                
                if(k < plain.size()){
                    v[i][j] = plain[k];
                    // cout << plain[k] << " " <<k << endl;
                    k++;
                }
                else{
                    v[i][j] = '*';
                }
            }
        }
    }
    
    // cout<< endl;

    vector<int> order(col);
    for(int i = 0 ; i < col ; i++){
        cin >> order[i];
    }
    map<int , pair<char, int>>mp;
    for(int i = 0 ;i < col ; i++){
        mp[order[i]] = {v[0][i], i};
    }
    string cipher= "";
    cout << "Cipher Text: " << endl;
    string nkey = "";
    for(auto &x:mp){
        for(int i = 1; i < row;i++){
            cout << v[i][x.second.second];
            cipher += v[i][x.second.second];
        }
    }
    cout << endl;

    decrypt(row , col , key , mp , v, cipher);
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