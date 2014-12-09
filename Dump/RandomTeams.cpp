#include <bits/stdc++.h>
using namespace std;

long long Pow(long long x,long long int pow) {
	if (pow == 0)
		return 1;

	if (pow % 2)
		return ((x % 1000000007) * Pow((x * x) % 1000000007, pow / 2))
				% 1000000007;

	else
		return Pow((x * x) % 1000000007, pow / 2) % 1000000007;
}

int main() {
	long long int t;
	cin>>t;
	if(t==0){
		cout<<1<<endl;
		return 0;
	}

	cout<<  ( (Pow(2,t-1) %1000000007)*  ((Pow(2,t)+1) %1000000007) ) %1000000007
			<<endl;
	return 0;
}
