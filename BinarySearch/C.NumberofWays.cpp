#include <bits/stdc++.h>

using namespace std;

#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
#define s second
#define f first

int main() {

	ll n;
	cin >> n;
	vector<ll> v(n);
	map<ll, vector<ll> > m;

	ll sum = 0, t = 0, num = 0;
	for (ll i = 0; i < n; i++) {
		cin >> v[i], sum += v[i];
		if (i < n - 1)
			m[sum].pb(i);
	}
	t = 0;


	for (ll i = n - 1; i > 1; i--) {
		t += v[i];
		if (m.count(t) && sum - t * 2 == t) {
			vector<ll>::iterator it = lower_bound(m[t].begin(), m[t].end(), i);

			ll idx = it - m[t].begin();
			if(idx>=sz(m[t]))
				idx=sz(m[t])-1;

			if (sz(m[t]) == 1)
				idx = 0;
			while (idx >= 0) {
				if (i - m[t][idx] > 1)
					break;
				idx--;
			}
			num += idx + 1;
		}
	}

	cout << num << endl;
	return 0;
}
