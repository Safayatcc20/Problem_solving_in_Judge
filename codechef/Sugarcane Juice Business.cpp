#include<bits/stdc++.h>'
using namespace std;
void solvec()
{
    long long n;
    cin >> n;
    long long rem = n * 50;
    cout << (long long)(rem - (rem * 0.2 + rem * 0.2 + rem * 0.3)) << "\n";
}
int main ()
{
    long long t;
    cin >> t;
    while(t--){
        solvec();
    }
}
