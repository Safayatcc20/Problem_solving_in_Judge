/*
 **** Bismillahir Rahmanir Rahim ****
 */
 
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
long long t = 1;
constexpr bool multiple_test_cases = 1;
long long gcd(long long x, long long y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
long long lcm(long long x, long long y)
{
    return ((x * y) / gcd(x, y));
}
const long long N = 10000;
long long prime[N];
long long fact(long long n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
long long findXor(long long n){//reming: function calling findXor(sending value - 1);
    long long rest = n % 4;
    if(rest == 0) return n;
    if(rest == 1) return 1;
    if(rest == 2) return n+1;
    if(rest == 3) return 0;
}
void solve(){
    long long q;
    cin >> q;
    multiset<long long>s;

    while (q--)
    {
        /* code */
        int choice;
        cin >> choice;
        if(choice == 1){
            long long x;
            cin >> x;
            s.insert(x);
        }
        else if(choice == 2){
            long long x, c ;
            cin >> x >> c;
            while (c-- and s.find(x) != s.end())
            {
                /* code */
                s.erase(s.find(x));
            }
            
        }
        else if(!s.empty()){
            
            long long mx  = INT_MIN , mn = INT_MAX;
            cout << *s.rbegin() - *s.begin() << sad;
        }
    }
    /* int Q;cin >> Q;
	set<int> set;
	map<int,int> mp;

	for(int i=0; i<Q; i++){
		int num;cin >> num;
		if(num == 1){
			int x;cin >> x;
			set.insert(x);
			mp[x]++;
		}else if(num == 2){
			int x,c;cin >> x >> c;
			mp[x] -= min(mp[x], c);
			if(mp[x] == 0){
				set.erase(x);
			}
		}else{
			cout << *set.rbegin() - *set.begin() << endl;
		}
	} */
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}

