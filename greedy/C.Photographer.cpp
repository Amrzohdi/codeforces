#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(v) (int)v.size()
int main(){
	long long c,mem,a,b;
	cin>>c>>mem;
	cin>>a>>b;
	vector < pair<long long,int> > v;
	int I=1;
	while(c--){
		long long x,y;
		cin>>x>>y;
		v.push_back( mp(x*a+y*b,I++) );
	}
	sort(v.begin(),v.end());
	vector <int> V;
	for(int i=0;i<sz(v);i++){
		if(mem-v[i].first>=0)
			mem-=v[i].first,V.push_back(v[i].second);
		else
			break;
	}
	cout<<sz(V)<<endl;
	for(int i=0;i<sz(V);i++)
		cout<<V[i]<<" ";
	return 0;
}
