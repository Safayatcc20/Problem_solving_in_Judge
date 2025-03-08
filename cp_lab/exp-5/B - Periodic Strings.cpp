/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
long long t = 1;
void KMP(string s , vector<int>&lps){
    int n = s.size();
    int len = 0 ;
    int i = 1;
    lps[0] = 0 ;
    while(i < n){
        if(s[i] == s[len]){
            i++, len++ , lps[i] = len;
        }
        else {
            if(len == 0){
                lps[i] = 0 , i++;
            }
            else{
                len = lps[len-1];
            }
        }
    }
}
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int>lps(n+1);
    KMP(s , lps);
    if(n % (n - lps[n])){
        cout << n << sad ;
    }
    else{
        cout << n - lps[n] << sad ;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    cin >> t;
    while (t--)
    {
        string b;
        getline(cin  , b);
        cin.ignore();
        solve();
        if(t){
            cout << sad;
        }
    }
}