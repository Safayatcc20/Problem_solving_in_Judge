

#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
long long t = 1; 
int power(int x, int n) {
  if (n == 1) return x ;
  int y = power(x, n / 2);
  if (n % 2 == 0) {
    return 1LL * y * y ;
  }
  else {
    return (1LL * y * y)  * x ;
  }
}
int main()
{
    int  x, n ;
    while(cin >> x >> n){
        cout << power(x , n) << '\n';
    }
}