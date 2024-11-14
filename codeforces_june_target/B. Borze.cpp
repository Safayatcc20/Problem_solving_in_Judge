/*
   **** Bismillahir Rahmanir Rahim ****
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
long long t = 1;
void solve()
{
    string s;
    cin >> s;
    string r = "";
    for(long long i = 0 ; i < s.size() ; ){
        if(s[i] == '.'){
            r +='0';
            i++;
        }
        else if(s[i] == '-' and s[i+1] == '.'){
            r+='1';
            i+=2;
        }
        else{
            r+='2';
            i+=2;
        }
    }
    cout << r << sad;
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //cin >> t;
    //while(t--){
        solve();
    //}
}