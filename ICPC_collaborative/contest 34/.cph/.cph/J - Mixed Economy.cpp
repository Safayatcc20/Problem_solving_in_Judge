//BISMILLAHIR RAHMANIR RAHIM
//ALLAHU AKBAR
#include<bits/stdc++.h>
using namespace std;


#define endl "\n"
#define int long long int
int ab[365]={0};

void fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

main()
{
    int n;
    cin>>n;
    int q;
    cin>>q;
    map<string,int> mp;
    vector<string> v;
    while(q--)
    {
        string s;
        cin>>s;
        int a;
        cin>>a;
        mp[s]-=a;
        v.push_back(s);
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        (*it).second+=100;
    }
    vector<pair<int,string>> u;
    int r = 0 ,count=0;
    for(int i=1;i<q;i++)
    {
        if(v[i-1]==v[i]) {
            count++; 
        }
        else
        {
            if(r == count){
                count = 0;
                continue;
            }
            r = count ;
            u.push_back(make_pair(count,v[i]));
            count=0;
        }
    }
    //sort(u.begin(),u.end());
    int sz=u.size();
    int prothom=0;
    string manush;
    for(int i=0;i<sz;i++)
    {
        if((u[i].first)>prothom)
        {
            prothom=u[i].first;
            manush=u[i].second;
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if((*it).first!=manush)
        {
            (*it).second+=r;
        }
        else
        {
            (*it).second-=(r*(n-1));
        }
    }
    int occho=INT_MIN,nimno=INT_MAX;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        occho=max(occho,((*it).second));
        nimno=min(nimno,((*it).second));
    }
    cout<<abs(occho-nimno)<<endl;
}