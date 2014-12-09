#include <bits/stdc++.h>
using namespace std;

int ar[1000];
vector<vector<pair<int, int> > > v;
int dij(int start) {
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, start));
	while (!q.empty()) {
		pair<int, int> Front = q.top();
		q.pop();

		Front.first *= -1;
		for (int i = 0; i < v[Front.second].size(); i++) {
			if (ar[v[Front.second][i].second] == -1
					|| Front.first + v[Front.second][i].first
							< ar[v[Front.second][i].second]) {
				ar[v[Front.second][i].second] = Front.first
						+ v[Front.second][i].first;
				q.push(
						make_pair(-ar[v[Front.second][i].second],
								(v[Front.second][i].second)));
			}
		}
	}
}
int main() {

	return 0;
}
