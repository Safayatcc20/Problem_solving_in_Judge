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
long long kuj(vector<long long>&v , long long s ,long long x){
    long long l = 0 , h = s , mid;
    while(l <= h){
        mid = (l + h) / 2;
        if(v[mid] == x){
            return 1;
        }
        if(v[mid] < x){
            h = mid;
        }
        else{
            l = mid;
        }
    }
    return -1;
}
void solve()
{
    long long n;
    cin >> n;
    map<long long , long long> mp;
    set<long long >ss, s;
    vector<long long > v(n) , vv;
    long long cnt = 0;
    for(auto &x:v) {
        cin >> x;
    }
    long long ind = -1;
    for(long long i = n-1; i >= 1; i--){
        if(v[i-1] > v[i]){
            ind = i;
            break;
        }
        else{
            vv.push_back(v[i]);
        }
    }
    for(long long i = 0; i < ind; i++){
        s.insert(v[i]);
        v[i] = 0;
    }
    for(long long i = ind; i< n ;i++){
        if(s.find(v[i]) == s.end()){
            continue;
        }
        else{
            v[i] = 0;
        }
    }
    if(is_sorted(all(v))){
        cout << s.size() << sad;
    }
    else{
        ind = -1;
        for(long long i = n-1; i >= 0; i--){
            if(v[i-1] > v[i]){
                ind = i;
                break;
            }
        }
        for(long long i = 0 ; i < ind ; i++){
            if(v[i] > 0){
                s.insert(v[i]);
            }
        }
        cout << s.size() << sad;
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