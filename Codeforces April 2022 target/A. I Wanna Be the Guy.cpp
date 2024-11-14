#include<bits/stdc++.h>
using namespace std;
#define sad '\n'
int main()
{
    long long n;
    cin >> n;
    long long p, j = 0;
    cin >> p;
    vector<long long>v(p) , vv(p) , vvv;
    set<long long>s;
    for(auto &x:v){ 
        cin >> x;
        s.insert(x);
    }
    for(auto &x: vv){
        cin >> x;
        s.insert(x);
    }
    vvv.assign(s.begin() , s.end());
    sort(vvv.begin() , vvv.end());
    long long cnt = 0;
    if(vvv.size() != n){
        cout << "Oh, my keyboard!" << sad;
        return 0;
    }
    cout << "I become the guy." << sad;   
}
