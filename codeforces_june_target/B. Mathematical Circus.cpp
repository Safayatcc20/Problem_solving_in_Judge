/*
   **** Bismillahir Rahmanir Rahim ****
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
long long t = 1;
void solve()
{
    long long n  , k , cnt = 0;
    cin >> n >> k;
    if(k % 4 == 0){
        cout << "NO" << sad;
        return ;
    }
    vector<long long>v;
    cout << "YES" << sad;
    for(long long i = 0; i < n ;i++){
        v.push_back(i+1);
    }
    map<long long , long long>mp;

    for(long long i = 0; i < n; i+=2){
        if(((v[i] + k ) * v[i+1]) % 4 == 0){
            cnt++;
            if(cnt <= n / 2){
            cout << v[i] << " " << v[i+1] << sad;
            mp[v[i]] = 1;
            mp[v[i+1]] = 1;
            }
        }
    }
    if(cnt < n/ 2){
        for(long long i = 1; i < n; i+=2){
            if(((v[i] + k ) * v[i-1]) % 4 == 0){
                cnt++;
                if(cnt <= n / 2 && mp[v[i]]!= 1 && mp[v[i-1]] != 1){
                    cout << v[i] << " " << v[i-1] << sad;
                }
            }
        }
    }
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}