#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 1e5 + 5,mod = 1e9 + 7;

#define int long long

int prime[M], n, m;
int b[N];
vector<int> primes;

map<int,int>mp;
int mul (int x , int y)
{
    x %= mod;
    y %= mod;
    return (x * y) % mod;
}
void sieve() {
    for (int i = 2; i < M; i++)
        prime[i] = i;
    for (int i = 2; (i * i) < M; i++) {
        for (int j = (i * i); j < M; j += i) {
            if (prime[i] == i) {
                prime[j] = i;
            }
        }
    }
}


int fastPower(int base, int power)
{
    if(!power)
        return 1;
    int half = fastPower(base,power / 2);
    int ans = mul(half,half);
    if(power & 1) ans = mul(ans,base);
    return ans;
}
int f(int x) {

    int ans = 1;
    map<int, int> mp2 = mp;
    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
             mp2[i]++;
             x /= i;
        }
    }
    if(x > 1) mp2[x]++;
    for (auto i: mp2)
    {
         ans = mul(ans,i.second + 1);

    }

    return ans;
}

signed main()
{
    sieve();
    cin >> n >> m;
    for (int i = 2; i <= 1e5; ++i)
    {
        if (prime[i] == i)
        {
            primes.push_back(i);
        }
    }

    for (int i = 2; i <= m; i++)
    {
        int x = i;
        for (int j = 2; j * j <= x; j++)
        {
            while (x % j == 0)
            {
                mp[j]++;
                x /= j;
            }
        }
        if(x > 1) mp[x]++;
    }
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        b[i] = f(x);
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}