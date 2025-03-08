//BISMILLAHIR RAHMANIR RAHIM
//ALLAHU AKBAR
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
main()
{
   //cout<<log2(31);
   int t;
   cin>>t;
   int o=1;
   while(t--)
   {
       int n,k;
       cin>>n>>k;
       int a[n];
       int sum=0;
       for(int i=0;i<n;i++)
       {
           cin>>a[i];
           sum+=a[i];
       }
       int sum1=0;
       for(int i=1;i<n;i++)
       {
           if(a[i]>=a[i-1])
           {
               sum1+=(a[i]-a[i-1])*(k-1);
           }
       }
       if(sum1==0)
        sum+=a[0]*(k-1);
       else
        sum+=sum1;
       cout<<"Case "<<o<<": ";
       cout<<sum<<endl;
       o++;
   }
}