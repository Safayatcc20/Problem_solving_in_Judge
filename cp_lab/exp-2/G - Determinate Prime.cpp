/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
const int N = 35000 + 10;
bool prime[N];
void sieve()
{
    prime[1] = prime[0] = true;
    for (int i = 3; i * i <= N; i += 2)
    {
        if (prime[i])
        {
            continue;
        }
        for (int j = i * i; j < N; j += i + i)
        {
            prime[j] = true;
        }
    }
}
bool isprime(int x)
{
    if (x == 2)
        return true;
    else if ((x % 2 == 0))
        return false;
    return !prime[x];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    bool flag = true;
    vector<vector<int>>ans;
    bool  f = true;
    vector<int>v;
    int cnt = 0, last = 0 , chk = 0;
    for(int i = 2; i < 35000; i++){
        if(isprime(i)){
            v.push_back(i);
            if(v.size() == 1){
                cnt = 1;
                last = i;
            }
            else if(v.size() == 2){
                cnt++;
                chk = i - last ;
                last = i;
            }
            else{
                if(i - last == chk){
                    cnt++;
                    last = i;
                }
                else{
                    if(cnt > 2){
                        vector<int>in;
                        for(int j = 0 ; j < v.size()-1; j++){
                            in.push_back(v[j]);
                        }
                        ans.push_back(in);
                        v.clear();
                        cnt = 2;
                        chk = 0;
                        v.push_back(last);
                        v.push_back(i);
                        chk = i  - last;
                        last = i;
                    }
                    else{
                        v.clear();
                        cnt = 2;
                        chk = 0;
                        v.push_back(last);
                        v.push_back(i);
                        chk = i  - last;
                        last = i;
                    }
                }
            } 
        }
    }
    int l , r;
    while(cin >> l >> r){
        if( l == 0 and r == 0){
            return 0;
        }
        for(int i = 0; i < ans.size(); i++){
            if(ans[i][0] >= l and ans[i][ans[i].size()-1] <= r){
                for(int j = 0 ; j < ans[i].size(); j++){
                    if(j == ans[i].size()-1){
                        cout << ans[i][j] ;
                        continue;
                    }
                    cout << ans[i][j] << " ";
                }
                cout << sad;
            }
        }
    }
}