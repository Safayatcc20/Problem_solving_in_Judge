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
    cin >> n;
    long long take = n;
    long long num = 0 ;
    while(take > 0){
        num = num * 10 + 1;
        take /= 10;
    }
    //cout << num << " ";
    while(n > 0){
        if(n < num){
            while(n < num and num > 11){
                num /= 10;
            }
        }
        n = n / num;
        cout << n << " "<< num << sad;
        if(n < 10){
            break;
        }
    }
    cout << n << sad;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}