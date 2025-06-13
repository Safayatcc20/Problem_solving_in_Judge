


// solution using manacher's algorithm
/***** Bismillahir Rahmanir Rahim *****/

#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
#define int long long
long long t = 1;
constexpr bool multiple_test_cases = 1;
string preprocess(const string &s)
{
    string t = "#";
    for (char c : s)
    {
        t += c;
        t += "#";
    }
    return t;
}
string s ;
int CountPalindrom()
{

    int N = s.size();
	vector<int> R(N);
	int i=0,j=0;
	while(i<N){
		while(i-j>=0 && i+j<N && s[i-j] == s[i+j]) ++j;
		R[i]=j;
		int k=1; 
		while(i-k>=0 && i+k<N && k+R[i-k]<j) R[i+k]=R[i-k],++k;
		i+=k,j-=k;
	}
	long long res = 0;
	for(int i = 0 ; i < N; i++) res += R[i]/2;
	return res;
}
// for odd length palindrome, p[i] = length of longest palindromic substring centered at i
// for even length palindrome, p[i] = length of longest palindromic substring centered between i and i+1
// the length of the longest palindromic substring is p[i] + 1 or p[i] + 2 depending on whether i is odd or even
// the number of palindromic substrings is (p[i] + 1) / 2 for odd length and (p[i] + 2) / 2 for even length
// total number of palidromic substr. count formula
// 1.total += (p[i] + 1) / 2 for odd length and
// 2.total += (p[i] + 2) / 2 for even length
// do it inside the for loop
void solve() {
    int n;
    cin >> n;
    string ops;
    cin >> ops;

    s = "$";  // same as Code 1
    for (int i = 0; i < n; ++i) {
        if (ops[i] == '-') {
            s.pop_back();  // pop '$'
            s.pop_back();  // pop actual character
        } else {
            s.push_back(ops[i]);
            s.push_back('$');  // add separator
        }
        cout << CountPalindrom() << " ";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
// Solution using brute force 
/* #include<bits/stdc++.h>
using namespace std;
#define sint short int
const int N=1e4+5;
vector<sint> vec[N];
int ans[N];
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    char a[N],s;
    int t=0,len=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%c",&s);
        if(s=='-')
        {
            vec[t].clear();
            ans[t]=0;
            if(len>0)
                len--,t--;
            printf("%d\n",ans[t]);
            continue;
        }
        a[++len]=s;
        for(int j=0;j<vec[t].size();j++)
        {
            sint pos=vec[t][j];
            if(a[pos-1]==s)
                vec[t+1].push_back(pos-1);
        }
        if(a[len-1]==s)
        {
            vec[t+1].push_back(len-1);
        }
        vec[t+1].push_back(len);
        t++;
        ans[t]=vec[t].size()+ans[t-1];
        printf("%d ",ans[t]);
    }
    return 0;
} */
