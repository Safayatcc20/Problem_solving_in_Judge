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
    long long r , c;
    cin >> r >> c;
    if(r == 1 || r == 15){
        cout << "black" << sad;
    }
    else if(r == 2 || r == 14){
        if(c == 1 || c == 15){
            cout << "black" << sad;
        }
        else{
            cout << "white" << sad;
        }
    }
    else if(r == 3 || r == 13){
        if(c == 2 || c == 14){
            cout << "white" << sad;
        }
        else{
            cout << "black" << sad;
        }
    }
    else if (r == 4 || r == 12){
        if(c == 1 || c == 15 || c == 3 || c == 13){
            cout << "black" << sad;
        }
        else{
            cout << "white" << sad;
        }
    }
    else if(r == 5 || r == 11){
        if(c == 2 || c == 14 || c == 4 || c == 12){
            cout << "white" << sad;
        }
        else{
            cout << "black" << sad;
        }
    }
    else if (r == 6 || r == 10){
        if(c == 1 || c == 5 || c == 11 || c == 3 || c == 13 || c == 15){
            cout << "black" << sad;
        }
        else{
            cout << "white" << sad;
        }
    }
    else if(r == 7 || r == 9){
        if(c == 2 || c == 14 || c == 4 || c == 12 || c == 6 || c == 10){
            cout << "white" << sad;
        }
        else{
            cout << "black" << sad;
        }
    }
    else if (r == 8){
        if(c == 1 || c == 5 || c == 11 || c == 3 || c == 13 || c == 15 || c == 7 || c == 9){
            cout << "black" << sad;
        }
        else{
            cout << "white" << sad;
        }
    }
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    //cin >> t;
    //while(t--){
        solve();
    //}
}