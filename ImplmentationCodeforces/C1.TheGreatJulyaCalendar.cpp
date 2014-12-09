#include <bits/stdc++.h>

using namespace std;

#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
#define s second
#define f first

int fun(int x){
	int num=0;
	while(x)
		num=max(num,x%10),x/=10;
	return num;
}
int main() {
	ios::sync_with_stdio(false);

	int n,t=0;
	cin>>n;
	while(n){
		n=n-fun(n);
		t++;
	}
	cout<<t<<endl;
	return 0;
}
