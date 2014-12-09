#include <bits/stdc++.h>

using namespace std;

#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
#define s second
#define f first
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll e, val;
		scanf("%Ld", &e);
		val = e;
		ll n, sqr = sqrt(e);

		for (int i = 1; i <= sqr + 1; i++)
			if (i * (2 * i - 1) <= e)
				n = i;

		ll idi = 1, idx = n + n - 1;
		e -= n * (2 * n - 1);
		if (e > 0) {
			e--;
			idx++;
		}
		while (e-- > 0) {
			idi++;
			idx--;
			if (idx == 1)
				break;
		}

		if (e > 0) {
			e--;
			idi++;
		}
		while (e-- > 0) {
			idx++;
			idi--;
		}
		printf("TERM %Ld IS %Ld/%Ld\n", val, idi, idx);
	}
	return 0;
}
