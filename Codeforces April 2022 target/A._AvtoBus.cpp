#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    long long x , y;
    if(n % 2 == 0 && n >= 4){
        if(n % 6 !=0){
            cout <<llround( n / 6 + 1) << " ";
        }
        else{
            cout << llround(n / 6) << " ";
        }
        cout << llround(n / 4) << "\n";
    }
    else{
        cout << - 1 << "\n";
    }
}
int main(){
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}