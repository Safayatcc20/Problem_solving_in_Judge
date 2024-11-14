#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long k, l, m, n, d, cnt = 0;
    cin >> k >> l >> m >> n >> d;
    for(long long i = 1; i <= d; i++){
        if(i % k != 0 || i % l != 0 || i % m != 0 || i % n != 0){
            cnt++;
        }
    }
    if( cnt == 0){
        cout << d << "\n";
    }
    else {
        cout << cnt << "\n";
    }
}
