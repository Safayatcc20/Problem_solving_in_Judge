#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    for(long long i = 0 ; i < n; i++ ){
        long long x = 1;
        long long z = 1, y = i;
        for(long long j = 0 ; j <= i; j++){
            cout << x << " ";
            x *= y;
            x /= z;
            y--;
            z++;
        }
        cout << "\n";
    }
}

