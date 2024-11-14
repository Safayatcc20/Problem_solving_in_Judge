#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n , m , k;
    cin >> n >> m >> k;
    string s, r;
    cin >> s >> r;
    string c;
    long long a = 0 , b = 0 ,i = 0 , j = 0;
    sort(s.begin(), s.end());
    sort(r.begin(), r.end());
    while( i < n && j < m){
        if(s[i] < r[j] && a < k){
            c += s[i];
            i++;
            a++;
            b = 0;
        }
        else if(s[i] > r[j] && b < k){
            c += r[j];
            j++;
            b++;
            a = 0;
        }
        else if(a < k){
            c += s[i];
            i++;
            a++;
            b = 0;
        }
        else if(b < k){
            c += r[j];
            j++;
            b++;
            a = 0;
        }
    }
    cout << c << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
