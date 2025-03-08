#include<bits/stdc++.h>
using namespace std;
#define all(n) n.begin() , n.end()
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n , cnt = 0 , m = 0, k;
    cin >> n >> k;
    vector<long long> v(n+1);
    for(long long i = 1; i <= n; i++){
        cin >> v[i];
        if(m <= v[i]){
            cnt++;
            m = v[i];
        }
    }
    if(is_sorted(all(v))){
            cout << "Yes";
            return 0;
    }
    long long lo = n - k;
    for(long long i = 1; i <= lo; i++){
        long long temp = v[i];
        v[i] = v[i+k];
        v[i+k] = temp;
        if(is_sorted(all(v))){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}


