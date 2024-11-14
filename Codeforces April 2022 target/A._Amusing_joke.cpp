//unsolved.

#include<bits/stdc++.h>
using namespace std;
int main ()
{
    string s, t, c;
    cin >> s >> t >> c;
    string ns;
    ns = s + t;
    cout << ns << "\n";
    sort(ns.begin(), ns.end());
    long long cnt = 0,rem = -1;
    for(long long i = 0 ; i < ns.size(); i++){
        for( long long j = 0; j < c.size(); j++){
            if(ns[i] == c[j]){
                cout << ns[i] << " ";
                if(j != rem){
                    rem = j;
                    cnt++;
                    break;
                }
            }
        }
    }
    if(cnt == ns.size()){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }
    return 0;
}
