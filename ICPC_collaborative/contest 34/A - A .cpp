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
long long gcd(long long x , long long y){
  if(y == 0) return x;
  return gcd(y , x % y);
}
void solve()
{
    long long n , m;
    cin >> n >> m;
    long long r , od , ev;
    if(n >= m){
        if((n - 1) % 3){
            r = (n - 1) / 3 + 1;
            if(r % 2){//t
                if((m - 1) % 2){
                    od = (m- 1) / 2 + 1;
                    if(od % 2 == 0){
                        cout << "Tuzik" << sad;
                    }
                    else{
                        cout << "Vanya" << sad;
                    }
                }
                else{
                    od = (m- 1) / 2 ;
                    if(od % 2 == 0){
                        cout << "Tuzik" << sad;
                    }
                    else{
                        cout << "Vanya" << sad;
                    }
                }
            }
             else{//v
                if((m - 1) % 2){
                    od = (m- 1) / 2 + 1;
                    if(od % 2 == 0){
                        cout << "Vanya" << sad;
                    }
                    else{
                        cout << "Tuzik" << sad;
                    }
                }
                else{
                    od = (m- 1) / 2 ;
                    if(od % 2 == 0){
                        cout << "Vanya" << sad;
                    }
                    else{
                        cout << "Tuzik" << sad;
                    }
                }
            }
        }
        else {
            r = (n - 1) / 3 ;
            if(r % 2){//t
                if((m - 1) % 2){
                    od = (m- 1) / 2 + 1;
                    if(od % 2 == 0){
                        cout << "Tuzik" << sad;
                    }
                    else{
                        cout << "Vanya" << sad;
                    }
                }
                else{
                    od = (m- 1) / 2 ;
                    if(od % 2 == 0){
                        cout << "Tuzik" << sad;
                    }
                    else{
                        cout << "Vanya" << sad;
                    }
                }
            }
            else{//v
                if((m - 1) % 2){
                    od = (n- 1) / 2 + 1;
                    if(od % 2 == 0){
                        cout << "Vanya" << sad;
                    }
                    else{
                        cout << "Tuzik" << sad;
                    }
                }
                else{
                    od = (m - 1) / 2 ;
                    if(od % 2 == 0){
                        cout << "Vanya" << sad;
                    }
                    else{
                        cout << "Tuzik" << sad;
                    }
                }
            }

        }
    }
    else{
        if((m - 1) % 2){
            r = (m - 1) / 2 + 1;
            if(r % 2){//t
                if((n - 1) % 3){
                    od = (n- 1) / 3 + 1;
                    if(od % 2 == 0){
                        cout << "Tuzik" << sad;
                    }
                    else{
                        cout << "Vanya" << sad;
                    }
                }
                else{
                    od = (n- 1) / 3;
                    if(od % 2 == 0){
                        cout << "Tuzik" << sad;
                    }
                    else{
                        cout << "Vanya" << sad;
                    }
                }
            }
             else{//v
                if((n - 1) % 3){
                    od = (n- 1) / 3 + 1;
                    if(od % 2 == 0){
                        cout << "Vanya" << sad;
                    }
                    else{
                        cout << "Tuzik" << sad;
                    }
                }
                else{
                    od = (n- 1) / 3;
                    if(od % 2 == 0){
                        cout << "Vanya" << sad;
                    }
                    else{
                        cout << "Tuzik" << sad;
                    }
                }
            }
        }
        else {
            r = (m - 1) / 2;
            if(r % 2){//t
                if((n - 1) % 3){
                    od = (n- 1) / 3 + 1;
                    if(od % 2 == 0){
                        cout << "Tuzik" << sad;
                    }
                    else{
                        cout << "Vanya" << sad;
                    }
                }
                else{
                    od = (n- 1) / 3 ;
                    if(od % 2 == 0){
                        cout << "Tuzik" << sad;
                    }
                    else{
                        cout << "Vanya" << sad;
                    }
                }
            }
            else{//v
                if((n - 1) % 3){
                    od = (n- 1) / 3 + 1;
                    if(od % 2 == 0){
                        cout << "Vanya" << sad;
                    }
                    else{
                        cout << "Tuzik" << sad;
                    }
                }
                else{
                    od = (n- 1) / 3 ;
                    if(od % 2 == 0){
                        cout << "Vanya" << sad;
                    }
                    else{
                        cout << "Tuzik" << sad;
                    }
                }
            }

        }
    }
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //long long t;
    cin >> t;
    while(t--){
        solve();
    }
}