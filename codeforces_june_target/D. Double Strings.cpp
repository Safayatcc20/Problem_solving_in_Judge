/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
void solve()
{
    long long n ;
    cin >> n;
    map<string , long long>mp;
    set<string>s;
    vector<string>v(n);
    for(auto &x:v){
        cin >> x;
        s.insert(x);
        mp[x] = 1;
    }
    for(long long i = 0; i < n ; i++){
       // cout << v[i] << sad;
        long long stop = 0;
        for(long long j = 0; j < v[i].size(); j++){
            string ft = v[i].substr(0 , j);
            string sec = v[i].substr(j, v[i].size());
            //cout << ft << " " << sec << " " ;            
            if(s.find(ft) != s.end()&& s.find(sec) != s.end()){
                cout << '1';
                stop = 1;
                break;
            }
            if(mp[ft] && mp[sec]){//set and map both same but using set running time decrease ;
                cout << '1';
                stop = 1;
                break;
            }
        }  
        if(!stop){
            cout << '0';
        }
    }
    cout << sad;
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