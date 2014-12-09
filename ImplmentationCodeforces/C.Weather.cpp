#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
int arpos[100009],arneg[100009];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	vector <int> v;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.pb(x);
	}

	int x=0;
	for(int i=0;i<n;i++){
		if(v[i]>=0)
			x++;
		arpos[i]=x;
	}
	x=0;
	for(int i=n-1;i>=0;i--){
		arneg[i]=x;
		if(v[i]<=0)
			x++;
	}

	int res=9999999;
	for(int i=0;i<n-1;i++)
		res= min(res,arpos[i]+arneg[i]);

	cout<<res<<endl;
	return 0;
}
