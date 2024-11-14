//unsolved;
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s.size() == 1){
            cout << "NO" << "\n";
        }
        else{
            long long cnt = 0, cnt2 = 0, a = 0, b = 0;
            for(long long i = 0; i < s.size()- 1; i++){
                if(s[i] != s[i+1] && s[i+1] != s[i+2] ){
                    cnt++;
                    //cout << s[i] << s[i+1] << s[i+2];
                }
            }
            if(cnt > 0){
                cout << "NO" << "\n";
            }
            else if(s[0] != s[1]){
                cout << "NO" << "\n";
            }
            else if(s[s.size() - 1] != s[s.size() - 2]){
                cout << "NO" << "\n";
            }
            else if( cnt == 0){
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
    }
}
//8 aaaabbb bbaaaaabbb aaaaaa abab a b aaaab bbaaa
