#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(v) (int)v.size()
int ar[1000];

void fun(int x,int y,vector <int> &v){
	if(x>y)
		swap(x,y);

	int T=0;
	for(int i=0;i<sz(v);i++)
		if(v[i]==x)
			{T=i;break;}

	if(x+T+1==y){
		ar[T+1]++;
		return ;
	}



}
int main(){
	int n;
	cin>>n;
	vector <int> v(n),V(n);
	int T=1;
	v[0]=V[0]=1;
	for(int i=1;i<n;i++,T++)
		v[i]=V[i]= v[i-1]+T;


	do{
		for(int i=0;i<n-1;i++)
			fun(v[i],v[i+1],V);
	}while(next_permutation(v.begin(),v.end()));


	for(int i=0;i<1000;i++)
		if(ar[i])
			cout<<i<<" "<<ar[i]<<endl;
	return 0;
}
