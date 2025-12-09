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
void KMP(string s , vector<int>&lps){
    int n = s.size();
    int len = 0 ;
    int i = 1;
    lps[0] = 0 ;
    while(i < n){
        if(s[i] == s[len]){
             len++ , lps[i] = len,i++;
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
    string t;
    int cnt = 1;
    vector<int>lps(s.size()+1);
    //cout << s.size() << sad;
    KMP(s , lps);  
    /* for(auto &x:lps){
        cout << x << " ";
    } */
    //cout << sad;
    int n = lps[s.size()-1];
    //cout << n << sad;
    for(int i = n ; i< s.size(); i++){
        if(cnt == 9) break;
        cnt++;
        t += s[i];
    }
    cout << t;
    if(t.size() != 8){
        for(int i = 0 ; i < t.size(); i++){
            if(cnt == 9) break;
            cnt++;
            cout << t[i];
            if(i == t.size()-1) i = -1;
        }
    }
    cout << "..." << sad;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}