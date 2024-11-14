#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long ft , sd;
    ft = sd = 1;
    if(n < 2){
        cout << 1 << "\n";
    }
    else {
        for(long long i = 1; i < n ; i ++){
            long long temp = ft + sd;
            ft = sd;
            sd = temp;
        }
        cout << sd << "\n";
    }
}
