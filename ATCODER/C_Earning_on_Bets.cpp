
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &x : v)
            cin >> x;
        vector<int> result(n);
        int l = 0, r = 1e9;
        while (l < r - 1)
        {
            int mid = l + (r - l) / 2;
            int jugfol = 0;
            for (int i = 0; i < n; i++)
            {
                result[i] = ceil(mid / v[i]);
                jugfol += result[i];
            }
            int guntechi = 0;
            for (int i = 0; i < n; i++)
            {
                if (jugfol < result[i] * v[i])
                    guntechi++;
            }
            if (guntechi < n)
            {
                r = mid;
            }
            else
                l = mid;
        }
        int jugfol = 0;
        for (int i = 0; i < n; i++)
        {
            jugfol += result[i];
        }
        int guntechi = 0;
        for (int i = 0; i < n; i++)
        {
            if (jugfol < result[i] * v[i])
                guntechi++;
        }
        if (guntechi < n)
        {
            cout << -1 << endl;
            continue;;
        }
        guntechi = 0;
        for (int i = 0; i < n; i++)
        {
            if (jugfol >= result[i] * v[i])
            {
                int prev = result[i];
                result[i] = jugfol / v[i] + 1;
                jugfol -= prev;
                jugfol += result[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (jugfol < result[i] * v[i])
                guntechi++;
        }
        if (guntechi < n)
        {
            cout << -1 << endl;
            continue;;
        }
        guntechi = 0;
        for (int i = 0; i < n; i++)
        {
            if (result[i] <= 1e9 * 1ll)
                guntechi++;
        }
        if (guntechi < n)
        {
            cout << -1 << endl;
            continue;;
        }
        for (auto &x : result)
            cout << x << " ";
        cout << endl;
    }
}