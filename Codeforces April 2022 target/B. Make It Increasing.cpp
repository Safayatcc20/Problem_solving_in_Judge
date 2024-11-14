#include<bits/stdc++.h>
using namespace std;
void div3b787()
{
    long long n;
    cin >> n;
    long long a[n];
    long long mx = 0;
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }
    long long reslt = 0;
    for(long long i = n-2; i >= 0; i--){
        while(a[i] >= a[i+1] && a[i] > 0){
            a[i] /= 2;
            reslt++;
        }
        if(a[i] == a[i+1]){
            cout << -1 << "\n";
            return;
        }
    }
    cout << reslt << "\n";
}
int main()
{
    long long t;
    cin >> t;
    while(t--){
        div3b787();
    }
}
