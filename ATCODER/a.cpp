#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long> v;
    if (n == 0)
    {
        cout << 0 << 0;
        return 0;
    }
    if (n < 10)
    {
        cout << 0 << n;
        return 0;
    }
    long long x = n;
    if (x == 10)
        cout << "0A";
    else if (x == 11)
        cout << "0B";
    else if (x == 12)
        cout << "0C";
    else if (x == 13)
        cout << "0D";
    else if (x == 14)
        cout << "0E";
    else if (x == 15)
        cout << "0F";
    else
    {
        long long cnt = 0;
        while (n != 0)
        {
            v.push_back(n % 16);
            n = n / 16;
            cnt++;
        }
        if (cnt < 2)
        {
            v.push_back(0);
        }
        reverse(v.begin(), v.end());
        for (auto &x : v)
        {
            if (x == 10)
                cout << "A";
            else if (x == 11)
                cout << "B";
            else if (x == 12)
                cout << "C";
            else if (x == 13)
                cout << "D";
            else if (x == 14)
                cout << "E";
            else if (x == 15)
                cout << "F";
            else
                cout << x;
        }
    }
}