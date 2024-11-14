//unsolved

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long rem = n / 26;
    long long r = n % 26;
    for(long long i = 0; i < rem ; i++){
        for(long long j = 1; j <= 26; j++){
            cout << char(96 + j )<< " ";
        }
    }
    for(long long i = 1; i <=r ; i++){
        if(i == r){
            cout << char(96 + r) << "\n";

        }
        else{
            cout << char(96 + i )<< " ";
        }
    }
}
