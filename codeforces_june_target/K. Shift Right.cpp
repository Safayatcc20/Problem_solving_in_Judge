#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    long long n = t;
    double sum = 0;
    while(t--){
        double x;
        cin >> x;
        sum += x;
    }
    cout << fixed << setprecision(7) << sum / n;
}


