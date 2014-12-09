#include <bits/stdc++.h>
using namespace std;

int main() {
	int TT;
	scanf("%d", &TT);
	while (TT--) {
		int n, p;
		scanf("%d%d", &n, &p);

		int T = 2 * n + p;

		for (int i = 1; i <= n; i++)
			for (int x = i + 1; x <= n; x++) {
				if (T-- > 0)
					printf("%d %d\n", i, x);
			}

	}
	return 0;
}
