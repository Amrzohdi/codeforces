#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)

int MX= (int)(2e7);
bool prime[(int)(2e7)];

void sieve(){
	memset(prime,1,sizeof(prime));
	prime[1]=prime[0]=0;

	for(ll i=2;i<MX;++i){
		while(!prime[i])
			i++;
		for(ll j=(ll)i*2;j<MX;j+=i)
			prime[j]=0;
	}
}
int main(){
	sieve();
	for(int i=1;i<1000;i++)
		if( *(prime+i) )
			printf("%d\n",i);

	return 0;
}
