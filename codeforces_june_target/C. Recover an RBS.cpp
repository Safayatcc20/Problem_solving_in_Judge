/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n'
bool check(string s){
    long long val = 0;
    for(long long i = 0; i < s.size() ; i++){
        if(s[i] == '(') val++;
        else val--;
        if(val < 0) return false;
    }
    return (val == 0);
} 
void solve()
{
    string s;
    cin >> s;
    /* if(s.size() % 2){
        cout << "NO" <<sad;
        return ;
    }
    if(s.size() < 3){
        cout << "YES" << sad;
        return ;
    }  */
    long long q = 0 , c = 0, o = 0;
    for(long long i = 0; i < s.size() ; i++){
        if(s[i] == '('){
            o--;
        }
        else if (s[i] == ')'){
            o++;
        }
        else {
            q++;
        }
    }
    long long open = (o+q) / 2;
    long long close = (q - o) / 2;
    //cout << open << close << sad;
    if(open == 0 || close == 0){
        cout << "YES" << sad;
        //cout << s << sad;
        return;
    }
    
    long long oo = -1, cc = 0;
    //string ss = "";
    string ss = string(open-1 , '(') + string(1 , ')') + string (1 , '(')+ string(close-1 , ')');
    
    /* for(long long i = 0; i < q ; i++){
        if(open--){
            ss +='(';
            continue;
        }
        if(cc == -1){
            ss +=')';
            cc = 0;
        }
        else if(oo == -1){
            ss +='(';
            oo = 0;
        }
        if(close--){
            ss +=')';
            //close--;
        }
    } */
   // cout << ss << sad;
    long long j = 0;
    for(long long i = 0; i < s.size(); i++){
        if(s[i] == '?'){
            s[i] = ss[j];
            j++;
        }
    }
    //cout << s <<sad;
    if(check(s)){
        cout << "NO" << sad;
    }
    else{
        cout << "YES" << sad;
    }
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}