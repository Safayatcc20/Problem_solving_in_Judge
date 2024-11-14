#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n, k, cnt = 0;
    cin >> n >> k;
    long long a[n];
    for(long long i = 0; i < n ; i++){
        cin >> a[i];
        if(5 - a[i] >= k){
            cnt++;
        }
    }
    cout << cnt / 3 << "\n";
    return 0;
}
