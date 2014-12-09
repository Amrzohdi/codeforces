#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
#define oo 10e6
vector<int> ranges;

int dp[51][51];
int best(int idxs, int idxe, int s, int e, int cuts) {

	if (idxs > idxe || cuts == sz(ranges) || s > e)
		return 0;

	int &res = dp[idxs][idxe];
	if (res != -1)
		return res;
	res = oo;
	for (int i = idxs; i <= idxe; i++)
		res = min(res,
				best(idxs, i - 1, s, ranges[i], cuts + 1)
						+ best(i + 1, idxe, ranges[i], e, cuts + 1) + e - s);
	return res;
}
int main() {
	ios::sync_with_stdio(false);

	int wood, pl;
	while (cin >> wood && wood) {
		cin >> pl;
		ranges.clear();
		memset(dp, -1, sizeof(dp));
		while (pl--) {
			int x;
			cin >> x;
			ranges.pb(x);
		}
		printf ("The minimum cutting is %d.\n",  best(0, sz(ranges) - 1, 0, wood, 0)  );
	}
	return 0;
}
