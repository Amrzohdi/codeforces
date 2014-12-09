#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)

int GreatestNumbersmallerORequalX(vector<long long> U, long long target) {
	long long f = 0, l = sz(U) - 1;
	while (f < l) {
		long long mid = (f + l) / 2;
		if (l - f == 1) {
			if (U[l] > target)
				return f;
			return l;
		}
		if (mid == sz(U))
			return sz(U) - 1;
		if (U[mid] == target)
			return mid;
		if (U[mid] > target)
			l = mid - 1;
		else if (U[mid] < target)
			f = mid;
	}
	return l;
}
int main() {
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		vector<ll> con(n), want, want1;
		for (int i = 0; i < n; i++)
			cin >> con[i];
		map<ll, int> m1, m2;
		int cum[10009], cum1[10009];
		memset(cum, 0, sizeof(cum));
		memset(cum1, 0, sizeof(cum1));
		for (int i = 0; i < n; i++) {
			int idx = GreatestNumbersmallerORequalX(want, con[i]);
			if (idx >= 0 && want[idx] <= con[i]) {
				if (want[idx] == con[i])
					cum[i] = m1[want[idx]];
				else
					cum[i] = m1[want[idx]] + 1, m1[con[i]] = cum[i];
				for (int x = idx; x < sz(want); x++) {
					if (want[x] < con[i])
						continue;
					if (m1[want[x]] <= cum[i])
						want.erase(want.begin() + x), x--;
					else
						break;
				}
				want.insert(lower_bound(want.begin(), want.end(), con[i]),
						con[i]);
			} else {
				want.insert(want.begin(), con[i]);
				m1[con[i]] = 1;
				cum[i] = 1;
			}
		}

		for (int i = n - 1; i >= 0; --i) {
			int idx = GreatestNumbersmallerORequalX(want1, con[i]);
			if (idx >= 0 && want1[idx] <= con[i]) {
				if (want1[idx] == con[i])
					cum1[i] = m2[want1[idx]];
				else
					cum1[i] = m2[want1[idx]] + 1, m2[con[i]] = cum1[i];
				for (int x = idx; x < sz(want1); x++) {
					if (want1[x] < con[i])
						continue;
					if (m2[want1[x]] <= cum1[i])
						want1.erase(want1.begin() + x), x--;
					else
						break;
				}
				want1.insert(lower_bound(want1.begin(), want1.end(), con[i]),
						con[i]);
			} else {
				want1.insert(want1.begin(), con[i]);
				m2[con[i]] = 1;
				cum1[i] = 1;
			}
		}

		int mx = 1;
		for (int i = 0; i < n; i++)
			mx = max(mx, min(cum[i], cum1[i]) * 2 - 1);
		cout << mx << endl;
	}
	return 0;
}
