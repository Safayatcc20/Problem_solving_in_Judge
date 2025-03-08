#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   /* string s;
    cin >> s;
    cout << s[s.size()-2] << s[s.size()-1] << "\n";*/
    long long t;
    cin>> t;
    long long a = t % 10;
    long long b = (t / 10)%10;
    cout << b << a;
}
