#include<bits/stdc++.h>
using namespace std;
void solveB()
{
    long long n , m;
    cin >> n >> m ;
    long long a[n], sum = 0;
    for(long long i = 0 ; i < n; i++){
        cin >> a[i];
    }
    if (n > m){
        cout << "NO" << "\n";
        return ;
    }
    sort(a , a + n);
    long long mx = INT_MIN, mn = INT_MAX;
    for(long long i = 0; i < n; i++){
        sum += a[i];
        mx = max(mx , a[i]);
        mn = min (mn , a[i]);
    }
   // cout << mx << " " << mn;
    if(n + sum - mn + mx > m){
        cout << "NO" << "\n";
    }
    else{
        cout << "YES" << "\n";
    }
}
int main()
{
    long long t;
    cin >> t;
    while(t--){
        solveB();
    }
}
