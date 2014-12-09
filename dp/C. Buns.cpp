#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
struct co{
	co(int x1,int y1,int z1,int w1){
		x=x1,y=y1,z=z1,w=w1;
	}
	int x,y,z,w;
};
vector<co> v;
int ar[1009][19];
int fun(int n,int idx){
	if(idx==sz(v))
		return 0;
	int &mx=ar[n][idx];
	if(mx!=-1)
		return mx;
	int i=0;
	while(v[idx].x>=i*v[idx].y &&	n>= i*v[idx].z )
		mx=max(mx,fun(n-i*v[idx].z,idx+1)+ i*v[idx].w),i++ ;
	return mx;
}
int main(){
	ios::sync_with_stdio(false);
	int n,m,c0,d0;
	cin>>n>>m>>c0>>d0;
	memset(ar,-1,sizeof(ar));
	v.pb(co(0,0,c0,d0));
	for(int i=0;i<m;i++){
		int x,y,z,w;
		cin>>x>>y>>z>>w;
		v.pb(co(x,y,z,w));
	}
	cout<<fun(n,0)<<endl;


	return 0;
}
