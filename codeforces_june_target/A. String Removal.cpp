#include<bits/stdc++.h>
using namespace std;
#define sad '\n'
void bcsa(){
    string s;
    cin >> s;
    long long a = 0 , b = 0;
    if(s.size() == 1 || s.size() % 2){
        cout << "NO" << sad;
        return;
    }
    for(long long i = 0  ; i < s.size(); i++){
        if(s[i] == 'a'){
            a++;
        }
        else{
            b++;
        }
    }
    if(a == b){
        cout << "YES" << sad;
    }
    else{
        cout << "NO" <<sad;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //bcsc();
    long long t;
    cin >> t;
    while(t--){
        bcsa();
    }
}