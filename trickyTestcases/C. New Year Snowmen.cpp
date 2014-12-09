#include <bits/stdc++.h>
using namespace std;
#define ll      long long
#define mp      make_pair
#define sz(v)   (int)v.size()
#define pb      push_back
#define b_p(n)      __builtin_popcount(n)
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		m[x]++;
	}

	set<pair<int, int> > se;
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		se.insert(mp(it->second * -1, it->first));

	vector<vector<int> > v;
	while (sz(se) >= 3) {
		set<pair<int, int> >::iterator it = se.begin();
		pair<int, int> p1 = *it, p2, p3;
		it++;
		p2 = *it;
		it++;
		p3 = *it;
		se.erase(p1);
		se.erase(p2);
		se.erase(p3);
		vector<int> V(3);
		V[0] = p1.second, V[1] = p2.second, V[2] = p3.second;
		v.pb(V);
		p1.first++;
		p2.first++;
		p3.first++;
		if (p1.first != 0)
			se.insert(p1);
		if (p2.first != 0)
			se.insert(p2);
		if (p3.first != 0)
			se.insert(p3);
	}

	cout << sz(v)<<endl;
	for (int i = 0; i < sz(v); i++) {
		sort(v[i].rbegin(), v[i].rend());
		cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << endl;
	}
	return 0;
}
