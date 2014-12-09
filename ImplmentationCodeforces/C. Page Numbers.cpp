#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
int main(){
	ios::sync_with_stdio(false);
	string s,res;
	cin>>s;
	bool ar[1009];

	memset(ar,0,sizeof(ar));

	for(int i=0;i<sz(s);i++){
		string S;
		int x;
		while(s[i]!=',' && i<sz(s))
			S+=s[i++];
		stringstream ss;
		ss<<S;
		ss>>x;
		ar[x]=1;
	}

	int st=-1,en=-1;
	for(int i=0;i<=1001;i++){
		if(ar[i]){
			if(st==-1)
				st=i;
			if(en==-1)
				en=i;
			else
				en++;
		}
		else {
			char re[10];
			if(st==-1)
				continue;
			if(st==en)
				sprintf(re,"%d,",st);
			else
				sprintf(re,"%d-%d,",st,en);
			st=-1,en=-1;
			res+= re;
		}
	}
	res.erase(res.end()-1);
	cout<<res<<endl;
	return 0;
}
