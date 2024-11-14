//unsolved;

#include<bits/stdc++.h>

using namespace std;
void solve()
{
    long long n;
    cin >> n;
    long long a[n];
    long long new_a[n];
    for(long long i = 0; i < n ; i++){
        cin >> a[i];
        //a[i] = a[i] + 1;
    }
    a[0]++;
    long long ans ;
    sort(a , a + n);
    for(long long i = 1 ; i < n; i++){
        if(a[i] == a[i - 1]){
            a[i]++;
        }
        else if(a[i] == a[i - 1] + 1){
            continue;
        }
        else if(a[i] == a[i - 1] + 2){
            a[i]--;
        }
        else{
            cout << "NO" << "\n";
            return ;
        }
    }
    cout << "YES" << "\n";
}
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
/*
#include<bits/stdc++.h>

using namespace std;
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long a[n];
        long long new_a[n];
        for(long long i = 0; i < n ; i++){
            cin >> a[i];
            a[i] = a[i] + 1;
        }
        if(n == 1){
            cout << "YES" << "\n";
        }
        else{
            new_a[0] = a[0];
            for(long long i = 1; i < n ; i++){
                if(a[i] - a[i-1] == 1){
                    new_a[i] = a[i];
                }
                else{
                    new_a[i] = a[i] - 2;
                    a[i] = a[i] - 2;
                    a[i-1] = a[i-1] - 1;
                }
            }
            long long cnt = 1;
            for(long long i = 1; i < n ; i++){
               if( a[i] - a[i-1] == 1){
                    cnt++;
                }
            }
            for(long long i = 0 ; i < n ; i++){
                cout << new_a[i] << " ";
            }
            cout << "\n";
            if(cnt == n-1 && (n == 2 || n == 3)){
                cout  << "YES" << "\n";
            }
            else if(cnt == n){
                cout << "YES" << "\n";
            }
            else{
                cout <<  "NO" << "\n";
            }
        }
    }
}

*/
