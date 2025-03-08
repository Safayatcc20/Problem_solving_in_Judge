#include <bits/stdc++.h>
using namespace std;
 
int main() {
     int a , b , c , d , day , hour  , mn;
     cin >> a >> b >> c >> d;
     if(a == b and a == c and a == d){
        cout << "O JOGO DUROU "<<24 << " HORA(S) E " << 0 << " MINUTO(S)" << endl;
        return 0 ;
     }
     mn = c * 60 + d - (a * 60) - b;
     hour = (mn / 60);
     mn = mn - hour * 60;
     if(mn < 0) {
        hour+= 23;
        mn = 60 + mn;
     }
     cout << "O JOGO DUROU "<< hour << " HORA(S) E " << mn << " MINUTO(S)" << endl;
    return 0;
}