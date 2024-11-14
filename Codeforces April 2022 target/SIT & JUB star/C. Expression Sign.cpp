#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a , b;
    cin >> a >> b;
    if(a == 0){
        cout << 0;
    }
    else if( b == 0){
        cout << 1;
    }
    else{
        if(b * log(a) > 0){
            cout << 1;
        }
        else{
            cout << -1;
        }
    }
}
