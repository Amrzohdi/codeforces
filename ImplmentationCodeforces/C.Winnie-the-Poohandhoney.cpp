#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,k;
	cin>>n>>k;
	ll res=0;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x>=k*3)
			res+= x- k*3;
		else if(x>=k*2)
			res+= x- k*2;
		else if(x>=k)
			res+= x- k;
		else
			res+= x;
	}
	cout<<res<<endl;
	return 0;

}
