#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
int main(){
	int n;
	cin>>n;
	int sz= n;
	if(sz%2!=0)
		sz--;
	vector <pair<int,int> > v(n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i].first);
		v[i].second=i+1;
	}
	sort(v.rbegin(),v.rend());

	vector <int> V[2];
	for(int i=0;i<sz;i++)
		V[i%2].pb(v[i].second);
	if(sz!=n)
		V[1].pb(v[sz].second);
	cout<<sz(V[0])<<endl;
	for(int i=0;i<sz(V[0]) ; i++)
		printf("%d ",V[0][i]);
	cout<<endl;
	cout<<sz(V[1])<<endl;
	for(int i=0;i<sz(V[1]);i++)
		printf("%d ",V[1][i]);
	cout<<endl;
	return 0;
}
