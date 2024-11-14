//unsolved

#include<bits/stdc++.h>
using namespace std;



int main()
{
    long long t;
    cin >> t;
    long long k;
    while(t--){
        string s;
        cin >> s;
        if(s[0] >= 'A' && s[0] <= 'Z' ){
            cout << "YES" << "\n";
        }
        else{
            sort(s.begin(), s.end());
            cout << s ;

        }
    }
}
