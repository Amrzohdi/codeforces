#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)

bool ar[4000];
int main(){
	memset(ar,0,sizeof(ar));
	int p,n;
	scanf("%d%d",&p,&n);
	int res=-1;
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		int z= x%p;

		if(res==-1 && ar[z])
			res=i;
		ar[z]=1;
	}

	cout<<res<<endl;
	return 0;
}
