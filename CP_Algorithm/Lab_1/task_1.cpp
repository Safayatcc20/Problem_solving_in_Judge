
#include <bits/stdc++.h>
using namespace std;
vector<int> bubble(vector<int>&v){
    for(int i = 0 ; i < v.size() ; i++){
        for(int j = 0 ; j < v.size(); j++){
            if(v[i] <= v[j]){
                int temp = v[j];
                v[j] = v[i];
                v[i] = temp;
            }
        }
    }
    return v;
}
int main()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &x:v) cin >> x;
    v = bubble(v);
    for(int i = 0 ; i < n ;i++){
        cout << v[i] << " ";
    }
    cout << endl;
}