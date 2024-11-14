//unsolve thinking  more .............
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n , m;
    cin >> n >> m;
    long long a[n];
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }
    long long mx = a[0];
    for(long long i = 0 ; i < n ; i++){
        mx = max(mx, a[i]);
    }
    int cnt[(mx + 1)];
    for(long long i = 0 ; i < mx + 1 ; i++){
        cnt[i] = 0;
    }
    for(long long i = 0 ; i < n ; i++){
        cnt[a[i]]++;
    }
    for(long long i = 1 ; i <= m ; i++){
        cout << cnt[i] << '\n';
    }
}
