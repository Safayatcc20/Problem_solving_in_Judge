#include <bits/stdc++.h>
using namespace std;

struct Interval {
    long long l, r;
    bool operator<(const Interval &other) const {
        return l < other.l;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int Q;
    cin >> N >> Q;

    set<Interval> black; 
    long long total_black = 0;

    while (Q--) {
        long long L, R;
        cin >> L >> R;

        long long newL = L, newR = R;

        // 1. Find first interval with l >= L
        auto it = black.lower_bound({L, R});
        for(auto  &x:black){
            cout << x.l << " "<< x.r << endl;
        }
        cout << it->l << " " << it->r << endl;

        // 2. Merge forward
        while (it != black.end() && it->l <= newR) {
            newL = min(newL, it->l);
            newR = max(newR, it->r);
            total_black -= (it->r - it->l + 1);
            it = black.erase(it);
        }

        // 3. Merge backward (previous interval)
        if (it != black.begin()) {
            auto it2 = prev(it);
            if (it2->r >= newL) {
                newL = min(newL, it2->l);
                newR = max(newR, it2->r);
                total_black -= (it2->r - it2->l + 1);
                black.erase(it2);
            }
        }

        // 4. Insert merged interval
        black.insert({newL, newR});
        total_black += (newR - newL + 1);

        // 5. Output remaining white cells
        cout << (N - total_black) << "\n";
    }

    return 0;
}
