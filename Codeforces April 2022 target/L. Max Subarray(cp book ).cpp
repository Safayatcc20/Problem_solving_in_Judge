//unsolved;
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    long long a[n];
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }
    long long subarray = INT_MIN, rem = INT_MIN;
    for(long long i = 0 ; i < n ; i++){
        for(long long j = i ; j < n ; j++){
            for(long long k = i ; k <= j; k++){
                rem = max(rem , a[k]);
            }
                subarray = max(subarray , rem);
        }
        cout << subarray << " ";
    }
    cout << "\n";
}
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
