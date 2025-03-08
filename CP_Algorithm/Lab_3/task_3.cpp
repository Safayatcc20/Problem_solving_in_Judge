#include <bits/stdc++.h>
using namespace std;
int maxsum(vector<int>&v , int l , int mid , int r ){
    int sum = 0 , lsum = INT_MIN, rsum = INT_MIN;
    for(int i = mid; i>= l ; i--){
        sum += v[i];
        if(sum > lsum) lsum = sum;
    }
    sum = 0 ;
    for(int i = mid; i<= r; i++){
        sum += v[i];
        if(sum > rsum) rsum = sum;
    }
    return max({lsum , rsum , lsum + rsum - v[mid]});
}
int subarraysum(vector<int>&v , int l , int r){
    if(l > r) return INT_MIN;
    if(l == r) return v[l];
    int mid = l + ( r - l) / 2;
    return max({subarraysum(v , l , mid-1) , subarraysum(v , mid+1 , r) , maxsum(v , l , mid , r)});
}
int main()
{
    int n ; cin >> n;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    cout << subarraysum(v , 0 , n-1 )<< endl;
    
}






