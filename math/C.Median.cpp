#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(v) (int)v.size()
int main(){
	int n,k;
	cin>>n>>k;
	vector <int> v(n);
	for(int i=0;i<n;i++)
		scanf("%d",&v[i]);
	sort(v.begin(),v.end());
	int T=0;
	while( v[((sz(v)+1)/2)-1] !=k ){
		v.push_back(k);
		sort(v.begin(),v.end());
		T++;
	}

	cout<<T<<endl;
	return 0;
}
