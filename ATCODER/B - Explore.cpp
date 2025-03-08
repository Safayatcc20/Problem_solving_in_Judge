/*
   **** Bismillahir Rahmanir Rahim ****
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n' 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n , m , t;
    cin >> n >> m >> t;
    vector<long long> v(n-1);
    for(auto &x:v){
        cin >> x;
    }
    vector<long long>r(n , 0);
    for(long long i = 0; i < m ;i++){
        long long x , y;
        cin >> x >> y;
        r[x-1] = y;
    }
    bool flag = false;
    long long sum = t;
    for(long long i = 0; i < n -1; i++){
        sum -= v[i];
       // cout << sum << sad;
        if(sum <= 0){
            flag = true;
            break;
        }
        else{
            sum += r[i+1];
        }
    }
    if(sum <= 0){
        cout << "No" << sad;
    }
    else if(flag){
        cout << "N0" << sad;
    }
    else{
        cout << "Yes" << sad;
    }
}