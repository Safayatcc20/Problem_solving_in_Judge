
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
int main()
{
    int n ;
    cin >> n;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    sort(all(v));
    int time;
    cin >> time;
    int ans = 0 , ind  = -1;
    for(int i = 0 ; i < n ; i++){
        //cout  << v[i] << sad;
        ans += v[i];
        if(ans > time){
            ind = i;
            break;
        }
    }
    if(ind == -1) ind = n;
    cout << ind << " jobs can be done."<< sad;
}








