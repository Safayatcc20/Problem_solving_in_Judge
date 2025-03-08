/*
   **** Bismillahir Rahmanir Rahim ****
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
long long t = 1;
void solve()
{
    
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long x , y , n ;
    cin >> x >> y >> n;
    if(n < 3){
        cout << x * n << sad;
    }
    else{
        long long sum;
        sum = (n / 3) * y +  x * (n % 3);
        long long ss = (n * x);
        cout << min(ss , sum) << sad;
    }
}