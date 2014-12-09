#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)

int dp[10009];
vector<int> v;
int fun(int idx) {

	if(idx==sz(v))
		return 0;
	if(dp[idx]!=0)
		return dp[idx];
	int res=0,cur=0;
	for(int i=idx;i<sz(v);i++){
		cur+=v[i];
		res= max(res,cur);
	}

	return dp[idx]=max(res,fun(idx+1));
}
int main() {

	int n;
	while (cin >> n && n) {
		memset(dp,0,sizeof(dp));
		v.clear();
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.pb(x);
		}
		int mx = fun(0);
		if (mx <= 0)
			cout << "Losing streak.\n";
		else
			printf("The maximum winning streak is %d.\n",mx);

	}

	return 0;
}
