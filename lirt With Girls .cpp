#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)

vector<pair<vector<int>, vector<int> > > V;
vector<string> vs;
int numofrooms(vector<int> v, int idx, int vis) {

}
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n,N;
		cin >> n;
		N=n;
		while (N--) {
			int x;
			cin >> x;
			pair<vector<int>, vector<int> > v1;
			while (x--) {
				int z;
				cin >> z;
				v1.first.pb(z);
			}
			cin >> x;
			while (x--) {
				int z;
				cin >> z;
				v1.second.pb(z);
			}
			V.pb(v1);
		}
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			vs.pb(s);
		}
	}
	return 0;
}
