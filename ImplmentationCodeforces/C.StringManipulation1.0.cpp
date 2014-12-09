#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
int main(){
	int k,n;
	string s,S;
	cin>>k>>s>>n;
	S=s;
	k--;
	while(k--)
		s+=S;
	vector <int> v[26];
	bool ar[200009];
	memset(ar,1,sizeof(ar));

	for(int i=0;i<sz(s);i++)
		v[s[i]-'a'].pb(i);


	while(n--){
		int x;
		char c;
		cin>>x>>c;
		int num= v[c-'a'][x-1];
		v[c-'a'].erase(v[c-'a'].begin()+x-1);
		ar[num]=0;
	}

	S="";
	for(int i=0;i<sz(s);i++)
		if(ar[i])
			S+=s[i];
	cout<<S<<endl;
	return 0;
}
