#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long t;
    cin >> t;
    while(t-- ){
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long ans1, ans2;
        ans1 = c - a;
        ans2 = d - b;
        if(ans1 >= 0 && ans2 >= 0){
            cout << "POSSIBLE" << "\n";
        }
        else{
            cout << "IMPOSSIBLE" << "\n";
        }
    }
}
