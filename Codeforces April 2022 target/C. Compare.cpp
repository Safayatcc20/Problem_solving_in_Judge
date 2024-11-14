//unsolved;

#include<bits/stdc++.h>
using namespace std;
int main ()
{
    string x , y;
    cin >> x >> y;
    for(long long i = 0 ; i < x.size(); i++){
        for(long long j = 0 ; j < x.size(); j++){
            if(x[i] < x[j]){
                char temp;
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
    for(long long i = 0 ; i < y.size(); i++){
        for(long long j = 0 ; j < y.size(); j++){
            if(y[i] < y[j]){
                char temp;
                temp = y[i];
                y[i] = y[j];
                y[j] = temp;
            }
        }
    }
    if( x.size() == y.size()){
        cout << x << "\n";
    }
    else if(x.length() < y.length()){
        cout << x << "\n";
    }
    else{
        cout << y << "\n";
    }
}
