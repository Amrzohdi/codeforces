#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
#define oo 10e8
vector<int> v;
int pumb(int s,int e){

	if(e<s)
		return 0;
	if(e-s+1==2)
		return 0;
	if(e-s+1==3)
		return v[s]*v[e];

	int res=0;
	for(int i=s+1;i<e;i++){
		res= max(res,  pumb(s,i)+pumb(i,e) +(v[s]*v[e])  );
	}
	return res;
}


int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		v.pb(x);
	}
	cout<<pumb(0,sz(v)-1);
	return 0;
}
