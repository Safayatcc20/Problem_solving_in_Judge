/*
   **** Bismillahir Rahmanir Rahim ****
*/

#include<bits/stdc++.h>
using namespace std;
#define sad '\n' 
#define all(b) b.begin() , b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long h , w;
    cin >> h >> w;
    char g[h][w];
    memset(g , -1  , sizeof(g));
    for(long long i = 0 ; i < h ; i++){
        for(long long j = 0; j < w; j++){
            cin >> g[i][j];
        }
    }
    map<long long , long long>mp;
    long long cnt = 0 , i  = 0 , j = 0;
    for(i = 0; i < h ; i++){
        for(j = 0; j < w; j++){
            if(i != 0 && g[i][j] == 'U' && mp[i+j] != 1){
                i-1 , j;
                mp[i+j] = 1;
                cnt++;
            }
            if(i != h - 1 && g[i][j] == 'D' &&mp[i+j] != 1){
                i+1 , j;
                mp[i+j] = 1;
                cnt++;
            }
            if(j != 0 && g[i][j] == 'L'  && mp[i+j] != 1){
                i , j-1;
                mp[i+j] = 1;
                cnt++;
            }
            if(j != w - 1 && g[i][j] == 'R' && mp[i+j] != 1){
                i , j + 1;
                mp[i+j] = 1;
                cnt++;
            }
            if((mp[i+j] == 1)){
                cout << - 1<< sad;
                return 0;
            }
            if( (i == 0 && g[i][j] == 'U') || (i == h - 1 && g[i][j] == 'D') || (j == 0 && g[i][j] == 'L') || (j == w - 1 && g[i][j] == 'R')){
                i+1 ;
                j + 1;
                break;
            }
        }
    }
    cout << i << " " <<  j << sad;
}