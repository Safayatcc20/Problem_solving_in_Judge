#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    long long x , y;
    if(n % 4 != 0 || n % 4 != 2 && n >= 4){
        cout << - 1 << "\n";
    }
    else{
        if(n % 6 !=0){
            cout <<llround( n / 6 + 1) << " ";
        }
        else{
            cout << llround(n / 6) << " ";
        }
        cout << llround(n / 4) << "\n";
    }
}
int main(){
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
