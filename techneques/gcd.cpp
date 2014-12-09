#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(v) (int)v.size()

ll gcd(ll x,ll y){
	if(y==0)
		return x;
	return gcd(y,x%y);
}
int main(){

	cout<<gcd(8,2)<<endl;
	return 0;
}
