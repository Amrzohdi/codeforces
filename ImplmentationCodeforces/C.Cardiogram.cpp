#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)

char ar[4000][1001];
int main() {
	int n;
	cin >> n;
	pair<int, int> p = mp(2000, 0);
	int mn = 999999, mx = -19;

	for (int i = 0; i < 4000; i++)
		for (int x = 0; x < 1001; x++)
			ar[i][x] = ' ';
	bool B = 0;
	char D[] = { '/', '\\' };
	while (n--) {
		mn = min(mn, p.first);
		mx = max(mx, p.first);
		int num;
		scanf("%d", &num);
		while (num--) {
			mn = min(mn, p.first);
			mx = max(mx, p.first);
			ar[p.first][p.second] = D[B];
			p.second++;
			if (B)
				p.first--;
			else
				p.first++;
		}
		B = !B;
		if (B)
			p.first--;
		else
			p.first++;
	}

	for (int i = mx; i >= mn; i--) {
		for (int x = 0; x < p.second; x++)
			printf("%c", ar[i][x]);
		cout << endl;
	}
	return 0;
}
