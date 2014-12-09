#include <bits/stdc++.h>

using namespace std;

int main() {

	int x;
	cin >> x;
	vector<int> v(x);
	for (int i = 0; i < x; i++)
		cin >> v[i];

	sort(v.rbegin(), v.rend());
	int i = 1, T = 3;
	vector<long long> V;
	V.push_back(v[0]);
	while (i < x) {
		int TT = T;
		T *= 4;
		V.push_back(0);
		while (TT--) {
			V[V.size() - 1] += v[i++];
		}
	}
	long long res = 0;
	T = V.size();
	for (int i = 0; i < V.size(); i++, T--)
		res += V[i] * T;
	cout << res << endl;
	return 0;
}
