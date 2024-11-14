#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n;
    cin >> n;
    long long a[n], x = 0, y = 0 , z = 0, r1[n], r2[n], r3[n];
    for(long long i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(long long i = 0 ; i < n ; i++){
        if(a[i] == 1){
            r1[x] = i+1;
            x++;
        }
        if(a[i] == 2){
            r2[y] = i+1;
            y++;
        }
        if(a[i] == 3){
            r3[z] = i+1;
            z++;
        }
    }
    long long w ;
    w = min (min (x, y), z);
    cout << w << "\n";
    for(long long i = 0, j = 0, k = 0; (i, j , k) < w; i++, j++, k++){
        cout << r1[i] << " " << r2[j] << " " << r3[k] << "\n";
    }
}
