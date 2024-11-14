#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin() , v.end());
        if(v[0] < 0){
            cout << v[0] << endl;
        }
        else cout << v[n-1] << endl;
    }

    return 0;
}
