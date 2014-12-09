#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(v) (int)v.size()

ll Pow(ll base, ll pow) {
	if (pow == 0)
		return 1;
	if (pow % 2)
		return base * Pow(base * base, pow / 2);
	else
		return Pow(base * base, pow / 2);
}

int main() {
	cout << Pow(2, 6);
	return 0;
}
