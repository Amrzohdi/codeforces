#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)

int main(){
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	vector<pair<int,int> > v;
	stack<int> st;
	for(int i=0;i<sz(s);i++){
		if(s[i]=='(')
			st.push(i);
		int x=-1;
		while(s[i]==')'){
			if(sz(st)){
				x=st.top();
				st.pop();
			}
			else
				break;
			i++;
			if(i==sz(s))
				break;
			if(s[i]=='(')
				st.push(i);
		}
		if(x!=-1)
			v.pb(mp(x,i-1));
	}

	int mx= -1;
	bool ar[1000009];
	memset(ar,1,sizeof(ar));
	sort(v.begin(),v.end());
	for(int i=0;i<sz(v);i++){
		if(v[i].second<mx)
			ar[i]=0;
		mx=max(mx,v[i].second);
	}
	vector <pair<int,int> > ac;
	for(int i=0;i<sz(v);i++)
		if(ar[i])
			ac.pb(v[i]);

	map<int,int>mp1;
	int curs=-3,cure=-3;

	for(int i=0;i<sz(ac);i++){
		if(cure+1==ac[i].first){
			cure=ac[i].second;
			if(i==sz(ac)-1)
				mp1[cure-curs+1]++;
		}
		else {
			if(curs!=cure)
				mp1[cure-curs+1]++;
			curs=ac[i].first; cure=ac[i].second;
			if(i==sz(ac)-1)
					mp1[cure-curs+1]++;
		}
	}
	pair<int,int> p=mp(0,1);
	for(map<int,int>::iterator it=mp1.begin();it!=mp1.end();it++)
		if(it->first>p.first)
			p=mp(it->first,it->second);


	cout<<p.first<<" "<<p.second<<endl;
	return 0;
}
