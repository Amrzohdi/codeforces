#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
#define oo  1e9
vector<pair<int,int> > v;
int memo[109];
int best(int c){
	if(c>=sz(v))
		return 0;
	int &re=memo[c];
	if(re!=-1)
		return re;
	re=oo;
	int sum= 0;
	for(int i=c;i<sz(v);i++){
		sum+= v[i].first;
		re= min(re,best(i+1)+ (sum+10)*v[i].second  );
	}
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		memset(memo,-1,sizeof(memo));
		v.clear();
		int x;
		cin>>x;
		for(int i=0;i<x;i++){
			int z,z2;
			cin>>z>>z2;
			v.pb(mp(z,z2));
		}
		cout<< best(0)<<endl;
	}
	return 0;
}
