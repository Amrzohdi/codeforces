#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
int ar[2][100009];
int main(){
	memset(ar,0,sizeof(ar));

	ar[0][0]=ar[1][0]=1;
	int n;
	cin>>n;
	vector <int> v(n);
	scanf("%d",&v[0]);
	vector <int> V(n);
	V[0]=v[0];
	for(int i=1;i<n;i++){
		int x;
		scanf("%d",&x);
		v[i]=x;
		V[i]=x;
		if(v[i-1]<v[i])
			ar[0][i]= ar[0][i-1]+1;

		if(V[i-1]<V[i]){
			ar[1][i]= ar[1][i-1]+1;
		}
		if(v[i-1]>=v[i]){
			ar[0][i]=1;
			ar[1][i]= ar[0][i-1]+1;
			V[i]=V[i-1]+1;
		}
		if(V[i-1]>=V[i]){
			ar[1][i]=ar[0][i-1]+1;
		}
}

	int mx=-1;
	for(int i=0;i<n;i++){
		mx=max(ar[0][i],max(ar[1][i],mx));
	}
	cout<<mx<<endl;
	return 0;
}
