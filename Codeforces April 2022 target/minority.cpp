//Unsolved


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    string str;
    ll t,len,count=0,count1=0;
    cin>>t;
    while(t--)
    {
        cin>>str;
        len=str.length();
        for(int i=0;i<len;i++)
        {
            if(str[i]=='1')
            {
                count++;

            }
            else if(str[i]=='0')
            {
                count1++;

            }

        }
        if(count==count1)
	{
		printf("0\n");

	}
	else if(count>count1)
	{
		printf("%d\n",count1);


	}
	else if(count<count1)
	{
		printf("%d\n",count);;

	}

    }
	return 0;
}
