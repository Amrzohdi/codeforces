#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	vector <int> v(n);
	for(int i=0;i<n;i++)
		scanf("%d",&v[i]);

	sort(v.rbegin(),v.rend());

	for(int i=1;i<=n;i++){
		for(int j=i-1;j<n;j++,k--){
			if(k==0)
				return 0;
			cout<<i<<" "<<v[j]<<" ";
			for(int x=0;x<i-1;x++)
				cout<<v[x]<<" ";

			cout<<endl;
		}
	}
	return 0;
}
