#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
void merge(vector<int>&v , int  l , int mid ,int r){
    //cout << l << " "<< mid <<  " " << r << sad;
    vector<int>left, right;
    for(int i = 0; i < mid - l + 1; i++){
        left.push_back(v[l+i]);
    }
    for(int i = 0; i < r - mid ; i++){
        right.push_back(v[mid + 1 + i]);
    }
    int k = l , i , j;
    for(i = 0 , j  = 0 ; i < mid - l + 1 and j < r - mid; k++){
        if(left[i] <= right[j]){
            v[k] = left[i];
            i++;
        }
        else{
            v[k] = right[j];
            j++;
        }
    }
    //cout << i << " " << j << sad;
    while(i < (mid - l + 1) ){
        v[k] = left[i];
        i++;
        k++;
    }
    while(j < r - mid  ){
        v[k] = right[j];
        k++ ; j++;
    }
}
void mergesort(vector<int>&v , int l , int r){
    if(l == r) return;
    //cout <<mid << sad;
    int mid = l + (r - l) / 2;
    mergesort(v , l , mid);
    mergesort(v , mid+ 1 , r);
    merge(v , l , mid , r);
}
int main()
{
    int n ;
    cin >> n;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    mergesort(v , 0 , n);
    for(auto &x:v) cout << x << " ";
}