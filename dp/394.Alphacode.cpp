#include <bits/stdc++.h>

using namespace std;

#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
#define s second
#define f first

string s;

bool Fun(int x, int y) {
	x -= '0';
	if (x == 0)
		return false;
	y -= '0';
	x *= 10;
	x += y;
	if (x <= 26)
		return true;
	return false;
}

ll ar[5009];
ll fun(int i) {

	if (ar[i] != -1)
		return ar[i];
	if (i == sz(s))
		return 1;

	ll count = 0;

	if (i < sz(s) - 1) {
		int x = sz(s) - i;
		if ((x >= 3 && s[i + 2] > '0') || (x <= 2))
			if (Fun(s[i], s[i + 1]))
				count += fun(i + 2);
	}

	if (s[i] != '0')
		count += fun(i + 1);
	return ar[i] = count;
}
int main() {

	while (cin >> s && s != "0") {
		memset(ar, -1, sizeof(ar));
		cout << fun(0) << endl;
	}
	return 0;
}
