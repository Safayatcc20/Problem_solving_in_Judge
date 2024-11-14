// unsolved;
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n , r , b;
    cin >> n >> r >> b ;
    if(r - b == 1){
        for(long long i = 0 ; i < n ; i++){
            if(i % 2 == 0){
                cout << 'R';
            }
            else{
                cout << 'B';
            }
        }
    }
    else{
        if(r % b == 0){
            for(long long i = 1 ; i <= n ; i++){
                if(i < r /b || i > r / b){
                    cout << 'R';
                }
                else{
                    cout << 'B';
                    
                }
            }
        }
        else{
            for(long long i = 0 ; i < n ; i++){
                if(i % 2 == 0){
                    cout << "R" << "\n";
                }
                else{
                    cout << "B" << "\n";
                }
            }
        }
    }
}
int main(){
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}