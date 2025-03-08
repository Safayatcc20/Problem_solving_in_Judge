/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
long long t = 1;
void solve(){
    long long n ;
    cin>> n;
    int ft = 0 , sec = 2  , trd = 1;
    if(n == 0){
        cout << "YES" << endl;
        return;
    }
    else if(n == 0){
        cout << "YES" << endl;
        return;
    }
    if(n == 0){
        cout << "YES" << endl;
        return;
    }
    for(long long i = 4;;i++){
        long long temp = trd;
        trd = ft + trd;
        ft= sec;
        sec = temp;
        if(trd == n){
            cout<< "YES" << endl;
            return;
        }
        if(trd > n){
            break;
        }
    }
    cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}