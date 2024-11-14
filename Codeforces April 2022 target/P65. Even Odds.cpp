#include<bits/stdc++.h>

using namespace std;
int main ()
{
    long long n , k ;
    cin >> n >> k;
    if( n % 2 == 0){
        long long rem = n / 2;
        if(rem >= k){
            cout << 2 * k - 1 << "\n";
        }
        else{
            cout << (k - rem) *2 << "\n";
        }
    }
    else{
        long long rem = n / 2 + 1;
        if(rem >= k){
            cout << 2 * k - 1 << "\n";
        }
        else{
            cout << (k - rem) *2 << "\n";
        }
    }
}

