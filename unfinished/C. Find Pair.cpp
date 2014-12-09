#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)



int main(){
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	vector <int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());

	int n1= k/n - (k%n==0)?1:0;

	k= k%n;
	k--;
	k+=n;
	k%=n;

	cout<<v[n1]<<" "<<v[k]<<endl;
	return 0;
}
