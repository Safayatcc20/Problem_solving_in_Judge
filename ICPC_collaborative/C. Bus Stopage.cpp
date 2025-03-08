//BISMILLAHIR RAHMANIR RAHIM
//ALLAHU AKBAR
#include<bits/stdc++.h>
using namespace std;


#define endl "\n"
#define int long long int
int sum=0;
//vector<int> v;
int coun=0;

void fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int fact(int n,int r)
{
    if(n==r) return 1;
    else return n*fact(n-1,r);
}

main()
{
    int t;
    cin>>t;
    int d=1;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v;
        int sum=0;
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            sum+=a;
            sum-=b;
            v.push_back(sum);
        }
        sort(v.begin(),v.end());
        int sz=v.size();
        cout<<"Case "<<d<<": "<<v[sz-1]<<endl;
        d++;
    }
}