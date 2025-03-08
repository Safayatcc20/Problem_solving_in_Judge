#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin >> n;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    int x;
    cin >> x;
    int l = 0, r = n , ind =- 1;
    while(l <= r){
        int mid = l + (r-l) /2;
        if(v[mid] == x){
            ind = mid;
            break;
        }
        if(v[mid] > x) r = mid-1;
        else l = mid+1;
    }
    if(ind == -1){
        cout << x << " is not found." << endl;
    }
    else{
        cout << x << " is found at index " << ind << endl;
    }
}