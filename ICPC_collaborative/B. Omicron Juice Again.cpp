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
        int a,b,c,k,div;
        cin>>a>>b>>c>>k;
        int sum=(a+b+c);
        div=sum/3;
        if(sum%3){
            cout<<"Case "<<d<<": Fight"<<endl;
        }else{
            a=abs(a-div);
            b=abs(b-div);
            c=abs(c-div);
            if(a%k==0 && b%k==0 && c%k==0){
               cout<<"Case "<<d<<": Peaceful"<<endl;
            }
            else{

        cout<<"Case "<<d<<": Fight"<<endl;

        }
    }
        d++;
    }
}