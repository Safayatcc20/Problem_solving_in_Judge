#include <atcoder/modint>
#include <bits/stdc++.h>

using namespace std;
using mint = atcoder::modint;

int main() {
	int n, m;
	cin >> n >> m;
	mint::set_mod(m);

	mint c = 1;
	for (int i = 1; i <= n; i++) {
		c = (c * i) + (i % 2 == 1 ? -1 : 1);
		cout << c.val() << ' ';
	}
	cout << endl;
}