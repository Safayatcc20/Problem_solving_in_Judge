#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>v(n);
        for(auto &x:v) cin >> x;
        bool f = false;
        for(int i = 0 ;i < n-1;i++){  
            int x = v[i] , y = v[i+1] ;
            if(min(x , y)* 2 > max(x ,y)){
                f = true;
                break;;
                
            }
        }
        if(f) cout << "YES"<< endl;
        else cout << "NO"<<endl;
    }
}