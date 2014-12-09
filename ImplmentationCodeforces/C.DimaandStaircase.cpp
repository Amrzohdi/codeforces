#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin>>n;
	long long ar[n];
	for(int i=0;i<n;++i)
		cin>>ar[i];
	cin>>n;
	long long ans[n];
	for(int i=0;i<n;i++){
		long long  w,h;
		cin>>w>>h;
		ans[i]=max(ar[0],ar[w-1]);
		ar[0]=ar[w-1]=max(ar[0],ar[w-1])+h;
	}

	for(int i=0;i<n;++i)
		cout<<ans[i]<<"\n";
	return 0;
}
