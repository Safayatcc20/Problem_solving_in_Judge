//BISMILLAHIR RAHMANIR RAHIM
//ALLAHU AKBAR
#include<bits/stdc++.h>
using namespace std;


#define endl "\n"
#define int long long int
int a[100000] = {0};

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
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int m=6;
        int i=0;
        int flag=true;
        long long sum = 0;
        while(k>1)
        {
            if(m==1)
            {
                flag=false;
                break;
            }
            if(k%m==0)
            {
                k=k/m;
                a[i]=m;
                i++;
            }
            else m--;
        }
        //cout << i << endl;
        if(flag==false) cout<<-1<<endl;
        else
        {
            int sum=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]==0)
            {
                sum+=1;
            }
            else
                sum+=a[j];
        }
        cout<<sum<<endl;
        }

    }
}