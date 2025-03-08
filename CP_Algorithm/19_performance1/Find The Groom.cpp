#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()

bool comp(pair<int, pair<int, pair<int, pair<string, int>>>>&a , pair<int, pair<int, pair<int, pair<string, int>>>>&b) {
    if(a.first > b.first) return true;    
    else if(a.first == b.first and a.second.first > b.second.first) return true;    
    else if(a.first == b.first and a.second.first == b.second.first and a.second.second.first < b.second.second.first) return true;    
    else if(a.second.second.second.first.size() < b.second.second.second.first.size()) return true;    
    else if(a.second.second.second.second < b.second.second.second.second) return true;
    else return false;    
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, pair<int, pair<int, pair<string, int>>>>> v(n);
    vector<string> name(n);
    for (int i = 0; i < n; i++) {
        cin>> name[i];
        cin >> v[i].first >> v[i].second.first >> v[i].second.second.first;
        v[i].second.second.second.first = name[i];
        v[i].second.second.second.second = i;
    }
    sort(all(v), comp);
    for (auto &x : v) {
        //cout << x.first << " " << x.second.first << " " << x.second.second.first << " " << x.second.second.second.first << x.second.second.second.second << sad;
        //cout << x.second.second.second.first.size() << sad;
        cout << x.second.second.second.second + 1 << sad;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
