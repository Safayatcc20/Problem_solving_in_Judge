#include<bits/stdc++.h>
using namespace std;
int main ()
{
    string s;
    cin >> s;
    for(long long i = 0 ; i < s.size(); i++){
        if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9'){
            cout << "YES" << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
}
