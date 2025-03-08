/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define int long long
long long t = 1;

string lcs(string  &s , string &t , vector<vector<string>>&dp,int i , int j , int m , int n ){
        if( i > m or j > n ) return "";
        if(dp[i][j] != "")  return  dp[i][j];
        if(s[i-1] == t[j-1]) dp[i][j] = s[i-1] + lcs(s , t , dp,i + 1, j +1 ,  m , n);
        else{
            string a = lcs(s , t , dp, i+1 , j  , m , n);
            string b = lcs(s , t , dp, i , j+ 1  , m , n);
            dp[i][j] = (a.size() > b.size()  ? a : b);
        }
        return dp[i][j];
}

void solve(){
    string s , t;
    cin >> s >> t;
    int m = s.size() , n = t.size()  ;
    //vector<vector<int>>dp(m + 1, vector<int>(n+ 1 , -1));
    vector<vector<string>> dp(m + 1, vector<string>(n + 1, ""));
    cout << lcs( s , t , dp, 1 , 1 , m , n ) << sad;
    
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