#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n;
    cin >> n;
    string s;
    cin >> s;
    if(n < 26){
        cout << "NO" << "\n";
    }
    else{
        long long cnt = 0;
        char rep = '0';
        for(long long i = 0; i < n; i++){
            s[i] = tolower(s[i]);
            for(long long j = 0 ; j < n ; j++){
                if(s[i] < s[j]){
                    char temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }
        for(long long i = 0 ; i < n; i++){
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
                if(s[i] != rep){
                    cnt++;
                    rep = s[i];
                    //cout << s[i] << " ";
                }
            }
        }
        if(cnt == 26){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}
