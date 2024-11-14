#include<bits/stdc++.h>
using namespace std;
void div3c787()
{
    string s;
    cin >> s;
    long long i = 0, len = s.length(),cnt = 1;
    long long j = len;
    while(s[i] != '0' && i < len - 1){
        i++;
    }
    while(s[j] != '1' && j > 0){
        j--;
    }
    cout << abs(i - j ) + 1 << "\n";
}
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        div3c787();
    }
}
