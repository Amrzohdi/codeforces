#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(v) (int)v.size()
int main(){
	int n,m;
	cin>>n>>m;
	vector <string> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];

	ll res=1;
	for(int i=0;i<m;i++){
		bool vis[50];
		memset(vis,0,sizeof(vis));
		ll t=0;
		for(int x=0;x<n;x++){
			if(vis[v[x][i]-'A'])
				continue;
			t++;
			vis[v[x][i]-'A']=1;
		}

		res= (res*t) %1000000007;
	}

	cout<<res<<endl;
	return 0;
}
