#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int *ar=new int[n+1];
	cin>>ar[0];
	for(int i=1;i<n;i++)
		cin>>ar[i],ar[i]+=ar[i-1];

	int res=0;
	for(int i=0;i<n-1;i++)
		if(ar[i]==ar[n-1]-ar[i])
			res++;

	cout<<res<<endl;
	return 0;
}
