
    /***** Bismillahir Rahmanir Rahim *****/

    #include <bits/stdc++.h>
    using namespace std;
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace std;
    using namespace __gnu_pbds;
    template <typename T>
    using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    #define sad '\n'
    #define all(b) b.begin(), b.end()
    #define ha cout << "YES" << '\n'
    #define na cout << "NO" << '\n'
    #define minusone cout << "-1" << '\n'
    #define int long long
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
    long long fact(long long n)
    {
        if (n == 0)
            return 1;
        return n * fact(n - 1);
    }
    long long findXor(long long n)
    { // reming: function calling findXor(sending value - 1);
        long long rest = n % 4;
        if (rest == 0)
            return n;
        if (rest == 1)
            return 1;
        if (rest == 2)
            return n + 1;
        if (rest == 3)
            return 0;
    }
    // Linear Diophantine Equation ax + by = c;
    // if c % gcd( a , b)  == 0 then solution exist otherwise not
    // solution by using  Extended Euclidean algorithm one solution
    int extgcd(int a, int b, int &x, int &y)
    {
        if (b == 0)
        {
            x = 1;
            y = 0;
            return a;
        }
        int x1, y1;
        int d = extgcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return d;
    }
    // Euler totient function for single call
    int phi(int n)
    {
        int ans = n;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                ans /= i;
                ans *= (i - 1);
                while (n % i == 0)
                    n /= i;
            }
        }
        if (n > 1)
            ans /= n, ans *= (n - 1);
        return ans;
    }
    // Euler totient preprocessing(from 1 to n ) in O(nloglog(n))
    vector<int> phai(1e7 + 10);
    void init()
    {
        // here check the problem requirement
        int maxn = 1e7 + 10;
        for (int i = 1; i <= maxn; i++)
        {
            phai[i] = i;
        }
        for (int i = 2; i <= maxn; i++)
        {
            if (phai[i] == i)
            {
                for (int j = i; j <= maxn; j += i)
                {
                    phai[j] /= i;
                    phai[j] *= (i - 1);
                }
            }
        }
        // here is the prefix sum of phai function
        // for(int i = 1; i <= maxn; i++){
        //     phai[i] += phai[i-1];
        // }
    }
    void solve()
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &x : v)
            cin >> x;

        vector<int> suf(n), pre(n);
        set<int> ans;
        ans.insert(0);
        map<int, int> mp;
        pre[0] = v[0];
        suf[n - 1] = v[n - 1];
        mp[v[n - 1]]++;
        int mn = 0;
        int mx = 0;
        int ind = n;
        for (int i = 1; i < n; i++)
        {
            mp[v[i]]++;
            if (v[i] != 1 and v[i] != -1)
            {
                ind = i;
            }
            ans.insert(v[i]);
            pre[i] = pre[i - 1] + v[i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            ans.insert(v[i]);
            suf[i] = suf[i + 1] + v[i];
        }
        for (int i = 0; i < n; i++)
        {
            mn = max({mn, pre[i]});
            mx = max({mx, pre[i]});
        }
        bool f = false;
        for (int i = 0; i < n; i++)
        {
            ans.insert(pre[i]);
            ans.insert(suf[i]);
        }
        for (int i = min(mn, mx); i <= max(mx, mn); i++)
        {
            ans.insert(i);
        }
        mn = 0, mx = 0;
        for (int i = 0; i < n; i++)
        {
            mn = max({mn, suf[i]});
            mx = max({mx, suf[i]});
        }
        for (int i = min(mn, mx); i <= max(mx, mn); i++)
        {
            ans.insert(i);
        }
        for (int i = 0; i < ind and ind < n; i++)
        {
            ans.insert(pre[ind] - pre[i]);
            ans.insert(suf[i] - suf[ind]);
        }

        for (int i = n - 1; i > ind and ind < n; i--)
        {
            ans.insert(pre[i] - pre[ind]);
            ans.insert(suf[ind] - suf[i]);
        }
        int prec = 0;
        int lmn = 0 , rmx = 0;
        mn = 0, mx = 0;
        for(int i = 0 ; i < ind and ind < n ;i++){
            prec += v[i];
            lmn = min(lmn, prec - mx);
            rmx = min(rmx, prec - mn);
            mn  = min(mn , prec);
            mx  = max(mx , prec);
        }
        for(int i = min(lmn, rmx); i<= max(rmx , lmn); i++){
            ans.insert(i);
        }
        prec = 0;
        lmn = 0 , rmx = 0;
        mn = 0, mx = 0;
        for(int i = ind ; i < n and ind < n ;i++){
            prec += v[i];
            lmn = min(lmn, prec - mx);
            rmx = min(rmx, prec - mn);
            mn  = min(mn , prec);
            mx  = max(mx , prec);
        }
        cout << ans.size() << sad;
        for (auto &x : ans)
            cout << x << " ";

        cout << sad;
    }
    int32_t main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr)->sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        // long long t;
        cin >> t;
        while (t--)
        {
            solve();
        }
    }