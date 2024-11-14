#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long t;
    cin >> t;
    while( t-- ){
        long long n;
        cin >> n;
        for(long long i = 1 ; i <= n; i++){
            cout << i << " ";
            for(long long j = n; j > 0 ; j--){
                if(i != j)
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0 ;
}
