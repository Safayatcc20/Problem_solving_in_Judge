#include<bits/stdc++.h>
#define ll long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define testing cout << "testing ";
#define mod 1000000007
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n,m;
string a,b;
int dp[5000][5000];
string dp1[30][30];
int len;
string s;
int lcs(int i,int j){

    if(i>=n or j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int ans=0;
    ans=lcs(i+1,j);
    ans=max(ans,lcs(i,j+1));
    ans=max(ans,lcs(i+1,j+1)+(a[i]==b[j]));

    return dp[i][j]=ans;
}

/* string findLCS(int i,int j){
    if(i==n or j==m) return "";
    if(!dp1[i][j].empty()) return dp1[i][j];
    if(a[i]==b[j]) return dp1[i][j]=(findLCS(i+1,j+1)+a[i]);
    string lcs1=findLCS(i+1,j);
    string lcs2=findLCS(i,j+1);

    return dp1[i][j]=(lcs1.size()>lcs2.size()?lcs1:lcs2);
} */


void do_the_honour(){

    memset(dp,-1,sizeof(dp));
    //for(int i=0;i<30;i++) for(int j=0;j<30;j++) dp1[i][j]="";
    cin >> a >> b;

    n=a.size();
    m=b.size();
    len=lcs(0,0);

    cout << len << endl;
    /* if(len==0) {
        cout << a << " " << b << endl;
        return;
    }
    string slcs=findLCS(0,0);
    reverse(slcs.begin(),slcs.end());


    string ansa;
    int k=0;
    for(int i=0;i<len;){
        if(a[k]==slcs[i]) {
            i++;k++;
        }
        else {ansa+=a[k];k++;}
    }
    while(k<n) ansa+=a[k++];
    string ansb;
    k=0;
    for(int i=0;i<len;){
        if(b[k]==slcs[i]) {
            i++;k++;
        }
        else {ansb+=b[k];k++;}
    }
    while(k<m) ansb+=b[k++];
    if(ansa.size()==0) cout << "Nil ";
    else cout << ansa << " ";

    if(ansb.size()==0) cout << "Nil " << endl;
    else cout << ansb<< endl; */

}

int main(){
    optimize();
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++){


        do_the_honour();


    }
    return 0;
}