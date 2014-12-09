#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)


bool prime[20000009];
int num[20000009];
int cum[20000009];
int MAX= 20000000;
void sieve(){
	memset(prime,1,sizeof(prime));
	prime[0]=prime[1]=0;
	for(int i=2;i<20000009;++i){
		while(!prime[i]){
		cum[i]=cum[i-1];
			i++;
		}

		cum[i]+=cum[i-1];
		for(int j=i;j<20000009;j+=i){
			prime[j]=0;
			cum[i]+= num[j];
		}
	}
}
int main(){

	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		num[x]++;
	}
	sieve();
	scanf("%d",&n);
	while(n--){
		int l,r;
		scanf("%d%d",&l,&r);
		r= min(r,MAX);
		l=min(l,MAX);
		printf("%d\n",cum[r]-cum[l-1]);
	}
	return 0;
}
