#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	priority_queue<pair<int, int> > q;
	vector <int> cost;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		q.push(make_pair(x, i));
		cost.push_back(x);
	}
	vector<pair<int, int> > v;
	for (int i = 0; i < m; ++i) {
		int x, y;

		scanf("%d%d", &x, &y);
		x--, y--;
		v.push_back(make_pair(x, y));
	}


	bool ar[9000];
	memset(ar, 0, sizeof(ar));
	long long res = 0;
	while (!q.empty()) {
		int idx = q.top().second;
		q.pop();
		for (int i = 0; i < m; ++i) {
			if (ar[i])
				continue;
			if (v[i].first == idx){
				res += cost[v[i].second];
//				cout<<v[i].first<<" "<<v[i].second<<" ";
			}
			if (v[i].second == idx){
				res += cost[v[i].first];
//				cout<<v[i].first<<" " << v[i].second;
			}
			if (v[i].first == idx || v[i].second == idx)
				ar[i] = 1;
//			cout<<endl;
		}
		cerr<<"   "<<res<<endl;
	}
	cout<<res<<endl;
	return 0;
}
