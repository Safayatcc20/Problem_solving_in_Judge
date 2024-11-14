/*
   **** Bismillahir Rahmanir Rahim ****
   **** Author: Md. Safayat Bin Nasir **** 
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
long long t = 1;
vector<long long > sq;
void sqr(){
    for(long long i = 0; i <= 2e5; i++){
        sq.push_back(i * i);
    }
}
void solve()
{
    long long n;
    cin >> n;
    vector<long long> v , vv;
    for(long long i  = 0 ; i < n ;i++){
        v.push_back(i);
    }
    vv.assign(v.begin() , v.end());
    long long ind = n - 1;
    while(ind >= 0){
        long long me = v[ind];
        long long you = *lower_bound(all(sq) , v[ind]);
        long long dif = you - me;
        reverse(vv.begin() + dif , vv.begin() + me + 1);
        ind = dif - 1;
    }
    for(auto &x: vv) cout << x << " ";
    cout << sad;
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    sqr();
    while(t--){
        solve();
    }
}
/*
   **** Bismillahir Rahmanir Rahim ****
   **** Author: Md. Safayat Bin Nasir **** 
*/
/*
#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
vector<long long> sq; 
void sqr(){
    for(long long i = 0; i < 1e6 ; i++){
        sq.push_back(i * i);
    }
}
long long bs(long long n){
    long long i = 0  , j = sq.size() - 1;
    long long mid , get;
    while (i <= j)
    {
        mid = (i + j ) / 2;
        if(sq[mid] >= n){
            j = mid - 1;
            get = sq[mid];
        }
        else{
            i = mid + 1;
        }
    }
    return get ;
}
void solve()
{
    long long n;
    cin >> n;
    vector<long long> v , vv;
    for(long long i  = 0 ; i < n ;i++){
        v.push_back(i);
    }
    vv.assign(v.begin() , v.end());
    long long ind = n - 1;
    while(ind >= 0){
        long long me = v[ind];
        long long you = bs(me);
        //cout << you << sad;
        long long dif = you - me;
        //cout << dif << sad;
        reverse(vv.begin() + dif , vv.begin() + me + 1);
        //for(auto &x: vv) cout << x << " ";
        //cout << sad;
        ind = dif - 1;
    }
    for(auto &x: vv) cout << x << " ";
    cout << sad;
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    sqr();
    while(t--){
        solve();
    }
}
//wrong submission & competitive programming; */