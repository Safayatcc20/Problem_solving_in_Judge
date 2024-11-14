#include<bits/stdc++.h>
using namespace std;
void maxsubarray(long long a[], long long ft, long long st)
{
    //cout << "[";
    long long mx = INT_MIN;
    for(long long i = ft; i < st; i++)
    {
        //cout << a[i] << ",";
        if(mx < a[i]){
            mx = a[i];
        }
    }
    long long ans = max (mx , a[st]);
    cout << ans << " " ;
    //cout << a[st] << "]" << "\n";
}
void subarray(long long a[], long long n)
{
    for(long long i = 0 ; i < n ; i++){
        cout << a[i] << " ";
    }
    for(long long i = 0 ; i < n ; i++){
        for(long long j = i + 1; j < n; j++){
            maxsubarray(a , i , j);
        }
    }
}
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long a[ n ];
        for(long long i = 0 ; i < n; i++){
            cin >> a[i];
        }
        subarray(a, n);
        cout << "\n";
    }
}
