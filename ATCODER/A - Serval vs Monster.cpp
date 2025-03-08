#include<bits/stdc++.h>
using namespace std;
#define sad '\n';
int main(){
  long long n , k;
  cin >> n >> k;
  long long cnt = 0;
  while(n > 0){
    cnt++;
    n -= k;
    //cout << n << sad;
  }
  cout << cnt << sad;
}