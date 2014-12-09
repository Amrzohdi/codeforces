#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(v) (int)v.size()

int k, d;

ll ar[109][2];

ll fun(int n, bool b) {
	if (n == 0 && b)
		return 1;
	if (n < 0)
		return 0;
	ll &res = ar[n][b];
	if (res != -1)
		return res;
	res = 0;
	for (int i = 1; i <= k; i++)
		res = (res + fun(n - i, (b | (i >= d)))) % 1000000007;

	return res;
}
int main() {
	int n;
	memset(ar, -1, sizeof(ar));
	cin >> n >> k >> d;

	cout << fun(n, 0) << endl;
	return 0;
}
