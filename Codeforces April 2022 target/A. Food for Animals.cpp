#include<bits/stdc++.h>
using namespace std;
void solve()
{
	long long a, b, c,  x , y;
	cin >> a >> b >>  c >> x >> y;
	if(a == b && b== c && c == x && x== y){
		cout << "YES" << "\n";
	}
	else{
        if(a < x && a + c < x){
            cout << "NO" << "\n";
        }
        else if(b < y && b + c < y){
            cout << "NO" << "\n";
        }
        else{
            if(a >= x){
                if(b >= y || b + c >= y){
                    cout << "YES\n";
                }
                else{
                    cout << "NO" << "\n";
                }
            }
            else if( a + c >= x ){
                if(b >= y){
                    cout << "YES\n";
                }
                else if((a+c+b - x) >= y){
                    cout << "YES" << "\n";
                }
                else{
                    cout << "NO" << "\n";
                }
            }
            else if(b >= y){
                if(a >= x || a + c >= x){
                    cout << "YES\n";
                }
                else{
                    cout << "NO" << "\n";
                }
            }
            else if( b + c >= y ){
                if(a >= x){
                    cout << "YES\n";
                }
                else if((a+c+b - y) >= x){
                    cout << "YES" << "\n";
                }
                else{
                    cout << "NO" << "\n";
                }
            }
            else{
                cout << "NO" << "\n";
            }
        }
	}
}
int main()
{
	long long t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}