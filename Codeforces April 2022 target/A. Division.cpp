#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        if( n < 1400){
            cout << "Division 4" << "\n";
        }
        else if (n < 1600){
            cout << "Division 3" << "\n";
        }
        else if(n < 1900){
            cout << "Division 2" << "\n";
        }
        else {
            cout << "Division 1" << "\n";
        }
    }
}
