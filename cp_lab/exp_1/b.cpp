/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <iostream>
#include<vector>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
void solve(){
    int n;
    while(cin >> n){
        vector<int>v(n);
        for(int i = 0 ; i < n ; i++){
            cin >> v[i];
        }
        int ans = 0 ;
        for(int i = 0 ; i < n-1; i++){
            for(int j = 0 ;j < n- i-1; j++){
                if(v[j] > v[j+1]){
                    int temp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = temp;
                    ans++;
                }
            }
        }
        cout << ans << sad;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}