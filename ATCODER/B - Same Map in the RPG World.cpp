#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> a(h), b(h);
    for (int i = 0; i < h; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < h; i++) {
        cin >> b[i];
    }

    bool found = false;
    for (int s = 0; s < h; s++) {
        for (int t = 0; t < w; t++) {
            vector<string> tmp(h);
            for (int i = 0; i < h; i++) {
                tmp[i] = a[(i+s)%h].substr(t) + a[(i+s)%h].substr(0, t);
            }
            if (tmp == b) {
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    if (found) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
