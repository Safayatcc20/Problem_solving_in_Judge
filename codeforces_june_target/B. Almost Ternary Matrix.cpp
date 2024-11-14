/*
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define end '\n' 
void solve()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            if(i % 2){
                if(j % 4 == 1 || j % 4 == 2){
                    cout << 1 << " ";
                }
                else{
                    cout << 0 << " ";
                }
            }
            else{
                if(j % 4 == 0 || j % 4 == 3){
                    cout << 1 << " ";
                }
                else{
                    cout << 0 << " ";
                }
            }
        }
        cout << "\n";
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