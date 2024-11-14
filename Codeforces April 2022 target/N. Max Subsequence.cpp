#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long  mx = 0;
    long long re = llround(pow(2, n));
    string r=" ";
    for(long long i = 0 ; i < re ; i++){
        for(long long j = 0; j < n; j++){
            if(i & (1 << j)){
                    /////solve.......
            }
        }
    }
    cout << mx << "\n";
}

