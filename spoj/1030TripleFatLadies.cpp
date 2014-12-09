#include <bits/stdc++.h>

using namespace std;

#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
#define s second
#define f first

bool fun(unsigned ll x) {

	if (x % 1000 == 888)
		return true;
	return false;
}
int main() {
	int t;
	scanf("%d", &t);

	int ar[] = { 942, 192, 442, 692 };
	while (t--) {
		ll k;
		scanf("%Ld", &k);
		ll l= k/4 + ((k%4)!=0) - 1;
		l*=1000;
		l+=ar[k%4];
		printf("%Ld\n",l);
	}

	return 0;
}
