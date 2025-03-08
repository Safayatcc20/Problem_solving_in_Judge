#include<bits/stdc++.h>
using namespace std;
void solveA()
{
    double x , y;
    cin >> x >> y;
    if(x * 1.07 >= y){
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

