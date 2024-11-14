#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    long long a[n];
    for(long long i = 0 ; i < n; i++){
        cin >> a[i];
    }
    long long ind = 0;
    for(long long i = 1 ; i < n; i++){
        if(a[i] < a[i-1]){
            ind = i - 1;
            break;
        }
    }
    cout << ind << "\n";
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
