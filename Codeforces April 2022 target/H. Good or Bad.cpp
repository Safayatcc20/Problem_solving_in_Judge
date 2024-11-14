#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        long long n = s.length();
        long long flag = 0;
        string r = " ";
        for(long long i = 0 ; i < n; i++){
            string r;
            for(long long j = i ; j < i+3; j++){
                r += s[j];
                if(r[0] == '0' && r[1] == '1' && r[2] == '0'){
                    flag = 1;
                    break;
                }
                else if(r[0] == '1' && r[1] == '0' && r[2] == '1'){
                    flag = 1;
                    break;
                }
                //cout << r << " " ;
            }
        }
        if(flag == 1 ){
            cout << "Good" << "\n";
        }
        else{
            cout << "Bad" << "\n";
        }
    }
}
