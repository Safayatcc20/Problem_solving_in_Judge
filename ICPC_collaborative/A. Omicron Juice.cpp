//BISMILLAHIR RAHMANIR RAHIM
//ALLAHU AKBAR
#include<bits/stdc++.h>
using namespace std;


#define endl "\n"
#define int long long int

void fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

main()
{
    int t;
    cin>>t;
    int d=1;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int sum=(a+b+c);
        if(sum%3==0) cout<<"Case "<<d<<": Peaceful"<<endl;
        else cout<<"Case "<<d<<": Fight"<<endl;
        d++;
    }
}