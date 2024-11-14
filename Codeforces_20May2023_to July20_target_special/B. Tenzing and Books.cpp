/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
long long t = 1;
void solve(){
    int n , x;
    cin >> n >> x;
    vector<long long>v1(n) ;
    vector<long long>v2(n) ;
    vector<long long>v3(n) ;
    for(auto &x:v1) cin >> x; 
    for(auto &x:v2) cin >> x; 
    for(auto &x:v3) cin >> x;
    int ans = 0;
    int i = 0 , j = 0 , k = 0;
    while(i < n || j < n || k < n){
        bool flag = false;
        if(i < n) {
            int xa = ans|x|v1[i];
            if(xa == x) {
                ans|= v1[i];
                i++;
                flag = true;
            }
        }        
        if(j < n) {
            int xb = ans|x|v2[j];
            if(xb == x) {
                ans|= v2[j];
                j++;
                flag = true;
            }
        }        
        if(k < n) {
            int xc = ans|x|v3[k];
            if(xc == x) {
                ans|= v3[k];
                flag = true;
                k++;
            }
        }    
        if(!flag){
            break;
        }
        if(ans == x) {
            cout << "Yes" << endl;
            return;
        }    
    }
    if(ans == x) {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}