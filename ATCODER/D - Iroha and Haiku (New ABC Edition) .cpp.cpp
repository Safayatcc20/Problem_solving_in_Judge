/*
   **** Bismillahir Rahmanir Rahim ****
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
long long t = 1;
void solve()
{
   long long n,p,q,r;
   cin>>n>>p>>q>>r;
   map<long long, long long>pos;
   long long sum = 0;
   vector<long long>v(n);
   for(auto &x:v) cin >> x;
   pos[0] = -1;
   for(long long i = 0; i < n ; i++)
   {
        sum+=v[i];
        if(sum>=(p+q+r) && pos.find(sum-r)!=pos.end() && pos.find(sum-r-q)!=pos.end() && pos.find(sum-r-q-p)!=pos.end())
        {
            cout<<"Yes"<<endl;
            return;
        }
        pos[sum] = i;
   }
    cout<<"No"<<endl;

}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    //cin >> t;
    //while(t--){
        solve();
    //}
}