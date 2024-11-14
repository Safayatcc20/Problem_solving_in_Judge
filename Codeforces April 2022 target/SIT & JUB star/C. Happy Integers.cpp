//unsolved


#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n, cnt = 0;
    cin >> n;
    long long sum = 9;
    for(long long i = 1; i <= n; i++){
        while(i > 0){
            if(sum >= i){
            sum = i % 10;
            i /= 10;
            cnt++;
            }
            else{
                break;
            }
        }
    }
    cout << cnt;
}

