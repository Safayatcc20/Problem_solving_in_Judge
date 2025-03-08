#include<bits/stdc++.h>
using namespace std;
void solveA()
{
    long long x , y;
    cin >> x >> y;
    if(x == y && (x,y) > 0){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }
}
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        solveA();
    }
}
