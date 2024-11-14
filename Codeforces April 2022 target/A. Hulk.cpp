#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n;
    cin >> n;
    for(long long i = 1; i <= n; i++){
        if(i %2 != 0){
            cout << "I hate ";
        }
        else{
            cout << "I love ";
        }
        if(i < n){
            cout << "that ";
        }
    }
    cout << "it";
}
