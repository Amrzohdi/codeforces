#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<int> v1(n),v2(n);
	for(int i=0;i<n;i++)
		cin>>v1[i],v2[i]= v1[i];
	sort(v1.begin(),v1.end());
	sort(v2.rbegin(),v2.rend());
	map<string,int> M;
	for(int i=0;i<m;i++){
		string s;
		cin>>s;
		M[s]++;
	}
	vector<int> V;
	for(map<string,int>::iterator it=M.begin();it!=M.end();it++)
		V.pb(it->second);
	sort(V.rbegin(),V.rend());

	int t1=0,t2=0;
	for(int i=0;i<sz(V);i++){
		t1+=v1[i]*V[i],t2+=v2[i]*V[i];
	}
	cout<<t1<<" "<<t2<<endl;
	return 0;
}
