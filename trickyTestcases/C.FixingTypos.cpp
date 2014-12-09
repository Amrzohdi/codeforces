#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(v) (int)v.size()

/*
 see this test aammaa
 */

int main(){
	string s,S;
	cin>>s;
	S+=s.substr(0,2);
	int count=1+ (S[0]==S[1]);
	for(int i=2;i<sz(s);i++){
		if(count+(s[i]==S[sz(S)-1]) >=3)
			continue;
		S+=s[i];
		count=1+ ( S[sz(S)-1]==S[sz(S)-2]  );
	}
	bool ar[200009];
	memset(ar,1,sizeof(ar));
	for(int i=0;i<sz(S)-3;i++)
		if( (S[i]==S[i+1]) & (S[i+2]==S[i+3])& ar[i] &ar[i+1]&ar[i+2] )
			ar[i+2]=0;
	s.clear();
	for(int i=0;i<sz(S);i++)
		if(ar[i])
			s+=S[i];
	cout<<s<<endl;
	return 0;
}
