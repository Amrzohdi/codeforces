#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)

vector<int> U;
int fun(int target) {
	int f = 0, l = sz(U) - 1;

	while (f < l) {
		int mid = (f + l) / 2;
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
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	vector<pair<int, int> > V;
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	int i = 1;
	V.pb(mp(0, 3));
	while (i < n) {
		if (v[i] > v[i - 1]) {
			int F = i - 1;
			while (v[i] > v[i - 1] && i < n)
				i++;
			V.pb(mp(F, 1));
		} else if (v[i] < v[i - 1]) {
			int F = i - 1;
			while (v[i] < v[i - 1] && i < n)
				i++;
			V.pb(mp(F, 2));
		} else {
			int F = i - 1;
			while (v[i] == v[i - 1] && i < n)
				i++;
			V.pb(mp(F, 3));
		}
	}

	int F = 0, last3 = -1;
	vector<pair<int, int> > vnum;
	if (V[0].second == 3) {
		last3 = 0;
		while (V[F].second == 3 && F < sz(V))
			F++;
		if (F == sz(V))
			vnum.pb(mp(0, n - 1));
	}

	while (F < sz(V)) {
		///////////////////////////////////////////
		if (V[F].second == 1) {
			int TT = F;
			if (last3 != -1)
				TT = last3;
			while (F < sz(V) && V[F].second != 2) {
				if (V[F].second == 3)
					last3 = F;
				else
					last3 = -1;
				F++;
			}
			while (F < sz(V) && V[F].second != 1) {
				if (V[F].second == 3)
					last3 = F;
				else
					last3 = -1;
				F++;
			}
			if (F != sz(V))
				vnum.pb(mp(V[TT].first, V[F].first));
			else
				vnum.pb(mp(V[TT].first, n - 1));
		} else if (V[F].second == 2) {
			int TT = F;
			if (last3 != -1)
				TT = last3;
			while (F < sz(V) && V[F].second != 1) {
				if (V[F].second == 3)
					last3 = F;
				else
					last3 = -1;
				F++;
			}
			if (F != sz(V))
				vnum.pb(mp(V[TT].first, V[F].first));
			else
				vnum.pb(mp(V[TT].first, n - 1));
		}
	}

	for (int i = 0; i < sz(vnum); i++)
		U.pb(vnum[i].first);

	while (q--) {
		int X, Y;
		scanf("%d%d", &X, &Y);
		X--, Y--;
		printf("\n");
		int pos = fun(X);

		if (Y <= vnum[pos].second)
			printf("Yes");
		else
			printf("No");
	}
	return 0;
}
