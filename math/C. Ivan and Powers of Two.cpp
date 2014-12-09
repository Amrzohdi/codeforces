#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)

vector<ll> fun(int x){
	vector<ll> v;
	while(x){
		ll i=1,t=0;
		while(i<=x)
			i*=2,t++;
		i/=2;
		x-=i;
		v.pb(t-1);
	}
	return v;
}
int main(){
	ios::sync_with_stdio(false);
	int n;

	cin>>n;
	map<ll,ll> m;
	ll in;
	for(int i=0;i<n;i++){
		cin>>in;
		m[in]++;
	}
	vector<ll> V;
	for(map<ll,ll>::iterator it=m.begin();it!=m.end();it++){
		vector<ll> v= fun(it->second);
		for(int i=0;i<sz(v);i++){
			if(v[i]==0)
				V.pb(it->first);
			else
				m[it->first+v[i]]++;
		}
	}
	ll res=V[0];

	for(int i=1;i<sz(V);i++)
		res+= V[i]-V[i-1]-1;
	cout<<res<<endl;
	return 0;
}
