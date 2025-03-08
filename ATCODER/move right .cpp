// AC
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    string s;
    cin >> s;
    string new_s;
    for(int i = 2, j = 3; i >= 0, j >=1 ; j--, i--){
        s [j] = s [i];
    }
    if (s [0] == '1'){
        s [0] = '0';
    }
    else{
        s [0] = '0';
    }
    cout << s << "\n";
}
