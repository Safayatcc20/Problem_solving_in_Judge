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
const int MAX = 1e6;
struct DS
{
    deque<int>dq;
    int rev = 0;
    long long sum = 0 ;
    void pop(){
        if(dq.size() == 0) return ;
        if(rev) {
            sum -= dq.front();
            dq.pop_front();
        }
        else {
            sum -= dq.back(); 
            dq.pop_back();
        }
    }

    void reverse(){
    rev ^= 1;
    }
    
    void besisize(){
        while(dq.size() > MAX){
            reverse();
            pop();
            reverse();
        }
    }

    void push(int x){
        sum += x;
        if(rev) dq.push_front(x);
        else dq.push_back(x);
        besisize();
    }

    void print(){
        if(dq.size() == 0){
            cout << "-" << sad;
            return;
        }
        if(rev) cout << dq.front() << sad;
        else cout << dq.back() << sad;
    }

    void repeat(int x){
        int sz = dq.size();
        int total = sz * x;
        int i = 0 ;
        reverse();
        while(total > 0 and dq.size() < MAX){
            if(rev) i = sz - i - 1;
            push(dq[i]);
            i  = (i+1) % sz;
            total--;
        }
        reverse();
    }
};

void solve(){
    string s;
    DS ans;
    while(cin >> s){
        if(s == "PUSH") {
            int x ;
            cin >> x;
            ans.push(x);
        }
        else if(s == "POP") {
            
            ans.pop();
        }
        else if(s == "SIZE") {
            cout << ans.dq.size() << sad;
        }
        else if(s == "PRINT") {
            ans.print();
        }
        else if(s == "SUM") {
            cout << ans.sum << sad;
        }
        else if(s == "REVERSE") {
            ans.reverse();
        }
        else if(s == "REPEAT") {
            int x ;
            cin >> x;
            ans.repeat(x);
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