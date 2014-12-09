#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back

bool primes[1000009];

void fun() {
	memset(primes,1,sizeof(primes));
	primes[0] = primes[1] = false;
	int m =1001;

	for (int i = 2; i <= m; i++)
		if (primes[i])
			for (int k = i * i; k <= 1000005; k += i)
				primes[k] = false;
	return;
}

int main() {
	fun();
	vector <int> v;
	int a,b,k;
	cin>>a>>b>>k;

	for(int i=a;i<=b;i++)
		if(primes[i])
			v.push_back(i);

	if(k>sz(v)){
		cout<<-1<<endl;
		return 0;
	}
	if(k==sz(v)){
		cout<< max( v[sz(v)-1]-a+1, b-v[0]+1 )<<endl;
		return 0;
	}
	int p1=0,p2=k;
	int mx=max(v[k-1]-a+1,b-v[sz(v)-k]+1);
	while(p2<sz(v)){
		mx=max(mx,v[p2++]- v[p1++]);
	}
	cout<<mx<<endl;

	return 0;
}
