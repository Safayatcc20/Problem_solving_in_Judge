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
#define int long long
long long t = 1;
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    deque<char>q;
    for (int i = 0; i < n; i++) {
        if (s[i] == ',') continue;
        if (s[i] == ')'){
            bool f1 = false, f2 = false;
            //char q.front = q.front();
                //cout << q.front() << sad;
            while (!q.empty() && (q.front() != '&' && q.front() != '|' && q.front() != '!')) {
                if (q.front() == 't') f1 = true;
                else if(q.front() == 'f') f2 = true;
                q.pop_front();
                //q.front = q.front();
            }
            if (!q.empty()) {
                if (q.front() == '&') {
                    q.pop_front();
                    q.push_front(f2 ? 'f' : 't');
                }
                else if (q.front() == '|') {
                    
                    q.pop_front();
                    q.push_front(f1 ? 't' : 'f');
                }
                else {
                    q.pop_front();
                    q.push_front(f2 ? 't' : 'f');
                }
            }
        }
        else q.push_front(s[i]);
    }
    char c = q.front();
    if(c == 't') cout << "true" << sad;
    else cout << "false" << sad;
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