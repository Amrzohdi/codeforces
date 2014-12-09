#include <bits/stdc++.h>

using namespace std;

#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
#define s second
#define f first

int fun(vector<int> def, vector<int> atk, multiset<int> se) {

	while (sz(def)) {
		multiset<int>::iterator it = upper_bound(se.begin(), se.end(), def[0]);

		if (it == se.end())
			return 0;

		se.erase(it);
		def.erase(def.begin());

	}

	int count = 0;
	while (sz(atk)) {
		multiset<int>::iterator it = lower_bound(se.begin(), se.end(), atk[0]);
		if (it == se.end() || *it != atk[0] ) {
			it = upper_bound(se.begin(), se.end(), atk[0]);
			if (it == se.end())
				return count;
			count += (*it - atk[0]);
			se.erase(it);
		} else
			se.erase(it);
		atk.erase(atk.begin());
	}

	for (multiset<int>::iterator it = se.begin(); it != se.end(); it++)
		count += *it;

	return count;
}
int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> def, atk, me;
	multiset<int> se, Se;
	for (int i = 0; i < n; i++) {
		string s;
		int x;
		cin >> s >> x;
		if (s == "DEF")
			def.pb(x);
		else
			atk.pb(x);
	}

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		se.insert(x);
		me.pb(x);
	}
	sort(def.begin(), def.end());
	sort(atk.begin(), atk.end());
	sort(me.rbegin(), me.rend());

	int count = fun(def, atk, se);
//	cout<<count<<endl;
	int i = 0, t = 0;

	while (i < min(sz(atk), sz(me)))
		t += max(me[i] - atk[i], 0), i++;

	cout << max(t, count) << endl;
	return 0;
}
