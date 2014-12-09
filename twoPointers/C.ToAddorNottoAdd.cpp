#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)

int main(){
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	vector <int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	int p1=0,p2=1;
	ll cum=0;

	pair<int,int>res=mp(1,v[0]);
	while(p2<n){
		cum=  cum+ (ll)((ll)(v[p2]-v[p2-1])*(ll)(p2-p1));
		while(cum>k && p1<p2){
			cum-= v[p2]-v[p1++];
		}
		if(res.first<p2-p1+1)
			res=mp(p2-p1+1,v[p2]);
		p2++;
	}

	cout<<res.first<<" "<<res.second<<endl;
	return 0;
}
