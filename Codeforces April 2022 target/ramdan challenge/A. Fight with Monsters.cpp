#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n ;
    cin >> n;
    long long a[n];
    for(long long i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    long long rem = 0, cnt = 0;
    for(long long i = 0 ; i < n ; i++){
        if(rem != a[i]){
            rem = a[i];
            cnt++;
        }
    }
    cout << cnt << "\n";
}
