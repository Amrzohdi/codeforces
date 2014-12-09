#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(v) (int)v.size()
int main() {

	int n, k;
	cin >> n >> k;
	if (n / k <= 2) {
		cout << -1 << endl;
		return 0;
	}
	int idx = 1;
	int K = 1;
	while (K <= k) {
		cout<<K<<" ";
		cout<<K<<" ";
		K++; idx+=2;
	}
	K = 1;
	while (K <= k)
		cout << K++ << " ", idx++;
	while (idx <= n)
		cout << k << " ", idx++;

	return 0;
}
