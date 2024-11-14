
#include <bits/stdc++.h>
using namespace std;
long long t = 1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >>m;
        long long ft = 0 , sec = 0;
        vector<long long>v(n)   ,  vv(m);
        for(auto &x:v) {
            cin >> x; 
            ft += x;
        }
        for(auto &x:vv) {
            cin >> x;
            sec += x;
        }
        if(ft > sec){
            cout << "Tsondu" << '\n';
        }
        else if(ft == sec) {
            cout << "Draw" << '\n';
        }
        else{
            cout << "Tenzing" << '\n';
        }
    }
}