#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
int ars1[50], ars2[50];

bool fun(int num) {
	int x = 0;
	for (int i = 0; i < 50; i++) {
		if (ars1[i] > ars2[i])
			return false;
		x+= max(ars2[i] - ars1[i], 0);
	}
	if (x == num)
		return true;
	return false;
}
int main() {
	string s1, s2;
	int num = 0, res = 0;
	cin >> s1 >> s2;

	for (int i = 0; i < sz(s2) ; i++)
		ars2[s2[i] - 'a']++;

	int i = 0;
	while (i < min(sz(s1), sz(s2))) {
		if (s1[i] == '?')
			num++;
		else
			ars1[s1[i] - 'a']++;
		i++;
	}
	int idx = 0;
	while (i < sz(s1) ) {
		if (fun(num))
			res++;

		if (s1[idx] == '?')
			num--;
		else
			ars1[s1[idx] - 'a']--;
		if (s1[i] == '?')
			num++;
		else
			ars1[s1[i] - 'a']++;
		i++;
		idx++;
	}
	if (fun(num))
		res++;

	cout<<res<<endl;
	return 0;
}
