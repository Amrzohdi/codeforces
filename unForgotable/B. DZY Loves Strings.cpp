#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)


int main(){
	string s;
	int n;
	cin>>s>>n;

	map<int,int> m;
	int mx=0;
	char A= 'a';
	for(int i=0;i<26;i++){
		int x;
		cin>>x;
		if(mx<x){
			mx=max(mx,x);
		A= (char)(i+'a');
		}
		m[i]=x;
	}


	string zz;
	while(n--)
		zz+= A;

	ll total=0;


	for(int i=0;i<=sz(s);i++){
		string Z="";
		Z= s.substr(0,i);
		Z+= zz;
		Z+= s.substr(i,sz(s)-i);
		ll to=0;
		for(int x=0;x<sz(Z);x++)
			to+= m[Z[x]-'a']*(x+1);
		total=max(total,to);
	}
	cout<<total<<endl;
	return 0;
}
