#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
int main(){
	string s;
	cin>>s;
	string h="hello";

	int idx=0;
	for(int i=0;i<sz(s) && idx<sz(h);i++){
		if(h[idx]==s[i])
			idx++;
	}

	if(idx==sz(h))
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}
