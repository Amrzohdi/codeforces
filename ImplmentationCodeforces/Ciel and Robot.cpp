//============================================================================
// Name        : codeforces.cpp
// Author      : Amr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
#define s second
#define f first

void fun(char s, pair<int, int> &p) {

	if (s == 'U')
		p.s-=1;

	else if (s == 'D')
		p.s -=-1;

	else if (s == 'R')
		p.f -= 1;
	else
		p.f -= -1;
}

bool Fun(pair<int, int> p1, pair<int, int> p2) {


	if( (p1.f ==0 && p2.f !=0) ||   (p1.s ==0 && p2.s !=0) )
		return false;

	bool b1=(p1.f ==0 && p2.f ==0),b2=(p1.s ==0 && p2.s ==0);

	int x1,x2;
	if(!b1){
		if( p2.f % p1.f!=0 )
			return false;
		x1= p2.f / p1.f;
		if(x1<0)
			return false;
	}
	if(!b2){
		if(p2.s % p1.s !=0)
			return false;
		x2= p2.s / p1.s;
		if(x2<0)
			return false;
	}
	if(b1 || b2)
		return true;
	if(x1==x2)
		return true;
	return false;

}
int main() {

	pair<int, int> xy;
	scanf("%d %d", &xy.f, &xy.s);
	string s;
	cin >> s;

	pair<int, int> p = make_pair(0, 0);

	for (int i = 0; i < sz(s); i++)
		fun(s[i], p);

	p.f*=-1;
	p.s*=-1;
	bool b = Fun(p, xy);

	for (int i = 0; i < sz(s); i++) {
		fun(s[i], xy);
		b |= Fun(p, xy);
	}

	if (b)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
