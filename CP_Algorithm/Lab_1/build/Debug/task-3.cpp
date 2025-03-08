#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , m;
    cin >> n;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    cin >> m;
    int l = 0, r = n ,ft = - 1 , last = -1;
    while(l <= r){
        int mid = l + (r-l) /2;
        if(v[mid] == m){
            ft = mid;
            r = mid - 1;
        }
        if(v[mid] > m) r = mid-1;
        else l = mid+1;
    }
    l = 0 , r = n;
    while(l <= r){
        int mid = l + (r-l) /2;
        if(v[mid] == m)   last = mid,l = mid + 1;
        if(v[mid] > m) r = mid-1;
        else l = mid+1;
    }
    if(ft == -1 and last == - 1) cout << m << " is absent." << endl;
    else cout << m << " is presented " << last - ft + 1 << " times"<< endl;
}