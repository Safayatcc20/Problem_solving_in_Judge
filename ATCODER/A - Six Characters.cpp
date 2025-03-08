#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    long long m = 0 , l = s.size();
    cout << s;
    for(long long i = 0; i < 6 - l; i++){
        cout << s[m] << "";
        m++;
        if(m >= l){
            m = 0;
        }
    }
}
