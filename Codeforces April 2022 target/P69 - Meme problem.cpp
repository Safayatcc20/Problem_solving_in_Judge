#include<bits/stdc++.h>

using namespace std;
int main ()
{
    string s;
    getline(cin , s);
    long long sum = 0;
    //cout << s[0];
    if(s[0] == 'c'){
        for(long long i = 0; i < s.length(); i++){
            if(s[i] >= 48 && s[i] <= 57){
                sum = sum * 10 + (s[i] - '0');
                //cout << sum << " ";
            }
        }
        cout << sum * 1 << "\n";
    }
    else if(s[0] == 'i'){
        for(long long i = 0; i < s.length(); i++){
            if(s[i] >= 48 && s[i] <= 57){
                sum = sum * 10 + (s[i] - '0');
                //cout << sum << " ";
            }
        }
        cout << sum * 4 << "\n";
    }
    else if(s[0] == 'l'){
        for(long long i = 0; i < s.length(); i++){
            if(s[i] >= 48 && s[i] <= 57){
                sum = sum * 10 + (s[i] - '0');
                //cout << sum << " ";
            }
        }
        cout << sum * 8 << "\n";
    }
}

