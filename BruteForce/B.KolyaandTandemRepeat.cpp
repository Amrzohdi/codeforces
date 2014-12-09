#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)


bool fun(string s){

	for(int i=0,j=sz(s)/2;j<sz(s);j++,i++){
		if(s[i]!=s[j]){
			if(s[i]!='*' && s[j]!='*')
				return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	int T;
	cin>>T;
	while(T--)
		s+='*';
	int t=0;
	for(int i=2;i<=sz(s);i+=2){
		string S;
		for(int x=0;x<=sz(s)-i;x++){
			if(x==0)
				S=s.substr(x,i);
			else{
				S+= s[x+i-1];
				S.erase(S.begin());
			}
			if(fun(S))
				t=max(t,sz(S));
		}
//		cout<<S<<endl;
	}
	cout<<t<<endl;
	return 0;
}
