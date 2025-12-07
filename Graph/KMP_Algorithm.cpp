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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        string s , t;
        cin >> s >> t;
        int n = s.size() , m = t.size();
        vector<int>lps(m+5) , ans;
        KMP(t , lps);
        int i = 0 , j = 0;
        while(i < n ){
            if(s[i] == t[j]){
                j++ , i++;
                if(j == m){
                    ans.push_back(i- j);
                    j = lps[j-1];
                }
            }
            else if(i < n and s[i] != t[j]){
                if(j == 0){
                    i++;
                }
                else {
                    j = lps[j-1];
                }
            }
        }
        if(!ans.size()){
            cout << "Not Found" << sad << sad;
            continue;
        }
        cout << ans.size() << sad;
        for(auto &x:ans){
            cout << x + 1<< " ";
        }
        cout << sad << sad;
    }
}