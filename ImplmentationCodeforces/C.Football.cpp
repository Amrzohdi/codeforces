#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(v) (int)v.size()
bool ar[1009][1009];

int main() {
	int n, k;
	cin >> n >> k;

	vector<pair<int, int> > v;
	for (int i = 1; i <= n; i++) {
		int T = k;
		for (int x = 1; x <= n; x++) {
			if (x == i || ar[i][x])
				continue;
			if (!T)
				break;
			v.push_back(mp(i, x));
			ar[x][i] = ar[i][x] = 1;
			T--;
		}
		if (T > 0) {
			cout << -1 << endl;
			return 0;
		}
	}

	printf("%d\n",sz(v));
	for (int i = 0; i < sz(v) ; i++)
		printf("%d %d\n",v[i].first,v[i].second);
	return 0;
}
