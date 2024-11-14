#include<bits/stdc++.h>
using namespace std;
void div2a789()
{
  long long n;
  cin >> n;
  long long a[n];
  for(long long i = 0; i < n; i++){
    cin >> a[i];
  }
  long long cnt = 0;
  for(long long i = 0; i < n; i++){
    if(a[i] == 0){
        cnt++;
    }
  }
  if(cnt > 0){
    cout << n - cnt << "\n";
  }
  else{
    sort(a , a + n);
    long long cnt[104] = {0}, frq = 0, mx = 0, ans = 0;
    for(long long i = 0; i < n; i++){
        cnt[a[i]]++;
    }
    for(long long i = 0 ; i < n; i++){
        if(cnt[a[i]] >= 2){
           ans = 1;
           break;
        }
    }
    /*for(long long i = 0; i < n ; i++){
        if(a[i] == a[i]){
            ans = 1;
            break;
        }
    }*/
    //cout << ans << "\n";
    if(ans == 1){
        cout << n << "\n";
    }
    else{
        cout << n + 1 << "\n";
    }
  }
}
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        div2a789();
    }
}

