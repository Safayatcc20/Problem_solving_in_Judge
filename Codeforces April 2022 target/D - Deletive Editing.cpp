#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string s , t;
    cin >> s >> t;
    long long n = s.size(), l = t.size();
    long long a[n] = {0};
    for(long long i = n - 1, j = l - 1; i >= 0; i--){
        if(a[s[i] - 'A'] == 1){
            continue;
        }
        if(s[i] == t[j]){
            --j;
        }
        else{
            a[s[i] - 'A'] = 1;
        }
        if(j < 0){
            cout << "YES" << "\n";
            return ;
        }
    }
     cout << "NO" << "\n";
}
int main()
{
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
