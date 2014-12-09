#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)

int wanted;
void fun(int x, int num) {
	if (num == wanted) {
		cout << x << endl;
		return;
	}

	for (int i = 1; i <= 3; i++)
		fun(x * 10 + i, num + 1);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> wanted;
	fun(0, 0);
	return 0;
}
