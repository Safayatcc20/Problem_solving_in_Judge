//unsolve////////////////////////
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n , w;
    cin >> n >> w;
    //vector<long long > v;
    long long store[w] = {0};
    long long a[n];
    for(long long i = 0 ; i < n; i++){
        //long long x;
        cin >> a[i];
        //v.push_back(x);
    }
    for(long long i = 0; i < n; i++){
        if(a[i] <= w){
            store[a[i]] = 1;
        }
    }
    for(long long i = 0; i < n; i++){
        for(long long j = i+1; j < n; j++){
            if(a[i]+a[j] <= w){
                store[a[i]+a[j]] = 1;
            }
        }
    }
    for(long long i = 0; i < n; i++){
        for(long long j = i+1; j < n; j++){
            for(long long k = j + 1; k < n; k++){
                if(a[i]+a[j] + a[k] <= w){
                    store[a[i]+a[j] + a[k]] = 1;
                }
            }
        }
    }
    long long ans = 0;
    for(long long i = 1; i <= w ; i++){
        ans+= store[i];
    }
    cout << ans ;
}

