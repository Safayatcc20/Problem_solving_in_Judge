
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
bool comp(pair<int , int>&a , pair<int , int>&b){
    return (a.second < b.second || a.second == b.second and a.first < b.first);
}
int main()
{
    int n ;
    cin >> n;
    vector<pair<int ,int>>v;
    for(int i = 0  ; i < n ; i++){
        int a , b;
        cin >> a >> b;
        v.push_back({a , b});
    }
    sort(all(v)  , comp);
    int a = 0 , b = 0, ans = 0, cnt = 0;
    for(auto &x:v){
        if(x.first >= b){
            a = x.first, b = x.second;
            ans++;
        }
    }
    cout << ans << " jobs can be done."<< sad;
}






