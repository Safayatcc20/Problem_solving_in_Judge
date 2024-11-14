#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n;
    cin >> n;
    long long a[n];
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }
    sort( a, a + n);
    long long sum = 0;
    for(long long i = 0; i < n; i++){
        sum += a[n-1] - a[i];
    }
    cout << sum << "\n";
}
