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
    long long b[n];
    for(long long i = 0 ; i < n; i++){
        b[i] = a[i];
    }
    long long ind = 0;
    sort(a , a+n);
    vector<long long > v;
    for(long long i = 0; i < n; i++){
        if(a[i] != b[i]){
            v.push_back(i);
        }
    }
    ind = v[0];
    for(long long i = 0; i < v.size(); i++){
        ind &= v[i];
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
