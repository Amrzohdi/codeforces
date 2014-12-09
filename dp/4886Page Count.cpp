#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)





int main() {
	int x;
	while (cin >> x && x) {
		string s, S;
		cin >> s;
		for (int i = 0; i < sz(s); i++)
			if (s[i] == ',')
				s[i] = ' ';
		vector<pair<int, int> > v;
		stringstream ss;
		ss << s;
		while (ss >> S) {
			if ((int) S.find('-') >= 0 && (int) S.find('-') < sz(S)) {
				pair<int, int> p;
				sscanf(S.c_str(), "%d-%d", &p.first, &p.second);
				if (p.first > p.second || max(p.first, p.second) <= 0
						|| min(p.first, p.second) > x)
					continue;
				p.first = max(1, p.first);
				p.second = max(1, p.second);
				p.second = min(x, p.second);
				p.first = min(x, p.first);
				v.pb(p);
			} else {
				stringstream ss1;
				ss1 << S;
				pair<int, int> p;
				ss1 >> p.first;
				p.second = p.first;
				if (p.first <= 0 || p.first > x)
					continue;
				v.pb(p);
			}
		}

		sort(v.begin(), v.end());
		int t = 0, mx = -1;
		for (int i = 0; i < sz(v); i++) {
			if (mx >= v[i].first)
				t += max(v[i].second - mx,0);
			else
				t += max(v[i].second - v[i].first + 1,0), mx = v[i].second;
			mx=max(mx,v[i].second);
		}
		cout << t << endl;
	}
	return 0;
}
