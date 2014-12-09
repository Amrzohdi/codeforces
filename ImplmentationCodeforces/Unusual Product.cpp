//============================================================================
// Name        : codeforces.cpp
// Author      : Amr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)

int main() {

	int n;
	scanf("%d",&n);
	int b = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int x;
			scanf("%d",&x);
			if (i == j)
				b ^= x;
		}

	cin >> n;
	while (n--) {
		int x;
		scanf("%d",&x);
		if (x == 3)
			printf("%d",b);
		else
			scanf("%d",&x), b ^= true;
	}
	return 0;
}
