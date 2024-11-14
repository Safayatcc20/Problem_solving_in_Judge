// solved first attempt;
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n;
    cin >> n;
    long long a[n];
    for(long long i = 0; i < n ; i++){
        cin >> a[i];
    }
    sort(a , a + n);
    long long cnt = 0;
    for(long long i = 0; i < n; i++){
        if(a[i] != i+1){
            cout << "NO" << "\n";
            return 0;
        }
        else{
            cnt++;
        }
    }
    if(cnt == n){
        cout << "YES" << "\n";
    }
}
