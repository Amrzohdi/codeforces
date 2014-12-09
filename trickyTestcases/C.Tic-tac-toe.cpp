#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)

string Find(string s[3]) {
	bool X = 0, O = 0;
	for (int i = 0; i < 3; i++) {
		if (s[i][0] == s[i][1] && s[i][2] == s[i][0] && s[i][0] == '0')
			O = 1;
		if (s[i][0] == s[i][1] && s[i][2] == s[i][0] && s[i][0] == 'X')
			X = 1;
		if (s[0][i] == s[1][i] && s[2][i] == s[0][i] && s[0][i] == '0')
			O = 1;
		if (s[0][i] == s[1][i] && s[2][i] == s[0][i] && s[0][i] == 'X')
			X = 1;
	}
	if (s[0][0] == s[1][1] && s[2][2] == s[0][0] && s[0][0] == '0')
		O = 1;
	if (s[0][0] == s[1][1] && s[2][2] == s[0][0] && s[0][0] == 'X')
		X = 1;
	if (s[0][2] == s[1][1] && s[2][0] == s[0][2] && s[0][2] == '0')
		O = 1;
	if (s[0][2] == s[1][1] && s[2][0] == s[0][2] && s[0][2] == 'X')
		X = 1;
	int numx=0,numo=0;
	for(int i=0;i<3;i++)
		for(int x=0;x<3;x++)
			if(s[i][x]=='0')
				numo++;
			else if(s[i][x]=='X')
				numx++;
	if( (O && X)  || (X&& numx!=numo+1 ) || (O && numo!=numx)  || abs(numo-numx)>=2)
		return "illegal\n";
	if(O)
		return "the second player won\n";
	if(X)
		return "the first player won\n";

	if(numx+numo==9  && numx!=numo+1)
		return "illegal\n";
	return "none";

}

int main() {
	string s[3];
	cin >> s[0] >> s[1] >> s[2];
	int x = 0, o = 0;
	for (int i = 0; i < 3; i++)
		for (int X = 0; X < 3; X++)
			if (s[i][X] == '0')
				o++;
			else if (s[i][X] == 'X')
				x++;

	if ( o>x || x>o+1 ){
		cout<<"illegal";
	}

	else if(o==1 && x==0)
		cout<<"illegal\n";
	 else if (Find(s) != "none")
		cout << Find(s) << endl;
	else if (x > o)
		cout << "second\n";
	else if (o >= x)
		cout << "first\n";
	return 0;
}
