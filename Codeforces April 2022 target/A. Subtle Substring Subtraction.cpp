#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    long long len = s.size(), sum = 0, sum1 = 0;
    if(len == 1){
        cout << "Bob " << s[0] - 96 << '\n';
    }
    else if( len % 2 == 0){
        for(long long i = 0; i < len; i++){
            sum += s[i] - 96;
        }
        cout << "Alice " << sum << "\n";
    }
    else if(s[0] == s[len - 1]){
        for(long long i = len - 2; i >= 0  ; i--){
            sum +=  s[i] - 96;
        }
        cout << "Alice " << sum - s[len - 1] + 96 << "\n";
    }
    else{
        if(s[0] < s[len - 1] ){
            for(long long i = 1; i < len  ; i++){
                sum +=  s[i] - 96;
            }
            cout << "Alice " << sum - s[0] + 96 << "\n";
        }
        else{
            for(long long i = 0; i < len - 1  ; i++){
                sum +=  s[i] - 96;
            }
            cout << "Alice " << sum - s[len - 1] + 96 << "\n";

        }
    }
}
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
