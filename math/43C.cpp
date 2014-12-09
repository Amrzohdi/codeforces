#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
int fun(int x){
	int res=0;
	while(x){
		res+= x%10;
		x/=10;
	}
	return res%3;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;

	int num3=0,num1=0,num2=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		x= fun(x);
		if(x==0)
			num3++;
		else if(x==2)
			num2++;
		else
			num1++;
	}

	printf("%d\n",  (num3/2) + min(num1,num2));
	return 0;
}
