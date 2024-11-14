#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        long long n, cnt = 0, rem = 0;
        cin >> n;
        for(long long i = 1;  ; i++){
            if( i % 3 != 0 && i % 10 != 3){
                cnt++;
                rem = i;
                if(cnt == n ){
                    cout << rem << "\n";
                    break;
                }
            }
        }
    }
}
