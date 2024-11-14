#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n ;
    string s;
    cin >> s;
    long long cnt = 0 , len = s.size();
    if((len - 1) % 2 == 0){
        cnt = 1;
    }
    else{
        cnt = 2;
    }
    for(long long i = (len -1)/2; i >= 0; i--){
        if(s[i] == s[i-1]){
            cnt += 2;
        }
        else{
            break;
        }
    }
    cout << cnt << "\n";
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
