#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(v) (int)v.size()

int n, m;
pair<int, int> fun990(int x, int y, int &num) {
	if (num >= 1) {
		num--;
		int N = n;
		swap(n, m);
		return mp(y, N - x + 1);
	}
	return mp(x, y);
}

pair<int, int> rotate(int x, int y, int num) {
	if (num == 0)
		return mp(x, y);
	return mp(x, m - y + 1);
}

pair<int, int> fun90(int x, int y, int &num) {
	if (num >= 1) {
		num--;
		int M = m;
		swap(n, m);
		return mp(M - y + 1, x);
	}
	return mp(x, y);
}
int main() {
	int x, y, hor, p;
	scanf("%d%d%d%d%d%d", &n, &m, &x, &hor, &y, &p);
	x %= 4;
	y %= 4;
	hor %= 2;

	while (p--) {
		int X, Y;
		scanf("%d%d",&X,&Y);
		int x1 = x, y1 = y;
		int N=n,M=m;
		pair<int, int> P = fun990(X, Y, x1);
		for (int i = 0; i < 3; i++)
			P = fun990(P.first, P.second, x1);
		P=rotate(P.first,P.second,hor);
		for (int i = 0; i < 3; i++)
			P = fun90(P.first, P.second, y1);
		printf("%d %d\n",P.first,P.second);
		m=M,n=N;
	}
	return 0;
}

