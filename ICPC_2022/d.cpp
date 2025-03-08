#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int t;
    cin>>t;
    int X=1;
    while(t--)
    {
        int a,b,c,k;
        cin>>a>>b>>c>>k;
        int flag=0;
        int count1=0,count2=0;
            int ans=(a+b+c)/3;

            if(a==ans) ;
            else if(a>ans)
            {
                int x=a-ans;
                if(x%k!=0) flag=1;
                else count1+=x/k;
            }
            else
            {
                int x=ans-a;
                if(x%k!=0) flag=1;
                else count2+=x/k;
            }
            if(b==ans) ;
            else if(b>ans)
            {
                int x=b-ans;
                if(x%k!=0) flag=1;
                else count1+=x/k;
            }
            else
            {
                int x=ans-b;
                if(x%k!=0) flag=1;
                else count2+=x/k;
            }
            if(c==ans) ;
            else if(c>ans)
            {
                int x=c-ans;
                if(x%k!=0) flag=1;
                else count1+=x/k;
            }
            else
            {
                int x=ans-c;
                if(x%k!=0) flag=1;
                else count2+=x/k;
            }
        
        //cout << count1 << " " << count2 << endl;
        //cout<<"Case "<<X<<": "<<ans<<endl;
        if(flag==0 && count1==count2)
        cout<<"Case "<<X<<": Peaceful"<<endl;
        else
            cout<<"Case "<<X<<": Fight"<<endl;
        X++;
    }
}