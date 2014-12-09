#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define sz(v) (int)v.size()

string ar = "RL";
string ar1 = "UD";
//s.append(&A[0],&A[strlen(A)]);
string fun(int x, int y, int &num) {
	string ss;
	char str[50];
	char gox = ar[(x < 0)], goy = ar1[(y < 0)];
	if (x != 0) {
		sprintf(str, "1 %d %c\n", abs(x), gox);
		ss.append(&str[0], &str[strlen(str)]);
		gox = ar[!(x < 0)];
		num++;
	}
	if (y != 0) {
		sprintf(str, "1 %d %c\n", abs(y), goy);
		ss.append(&str[0], &str[strlen(str)]);
		goy = ar1[!(y < 0)];
		num++;
	}
	ss += "2\n";
	if (y != 0) {
		sprintf(str, "1 %d %c\n", abs(y), goy);
		ss.append(&str[0], &str[strlen(str)]);
		goy = ar1[!(y < 0)];
		num++;
	}
	if (x != 0) {
		sprintf(str, "1 %d %c\n", abs(x), gox);
		ss.append(&str[0], &str[strlen(str)]);
		gox = ar[!(x < 0)];
		num++;
	}
	ss += "3";
	num += 2;
	return ss;
}
int main() {

	int n;
	cin >> n;
	vector<string> s;
	vector<pair<int, int> > ru, rd, lu, ld, vxpos, vypos, vxneg, vyneg;

	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x > 0 && y > 0)
			ru.pb(mp(x, y));
		else if (x > 0 && y < 0)
			rd.pb(mp(x, y));
		else if (x < 0 && y > 0)
			lu.pb(mp(x, y));
		else if (x < 0 && y < 0)
			ld.pb(mp(x, y));
		else if (x == 0 && y > 0)
			vxpos.pb(mp(x, y));
		else if (y == 0 && x > 0)
			vypos.pb(mp(x, y));
		else if (x == 0 && y < 0)
			vxneg.pb(mp(x, y));
		else if (y == 0 && x < 0)
			vyneg.pb(mp(x, y));
	}
	vector<string> res;
	int tot = 0;
	sort(vxpos.begin(), vxpos.end());
	sort(vypos.begin(), vypos.end());
	sort(vxneg.rbegin(), vxneg.rend());
	sort(vyneg.rbegin(), vyneg.rend());
	sort(ru.begin(), ru.end());
	sort(rd.rbegin(), rd.rend());
	sort(lu.begin(), lu.end());
	sort(ld.rbegin(), ld.rend());
	for (int i = 0; i < sz(vxpos) ; i++)
		res.pb(fun(vxpos[i].first, vxpos[i].second, tot));
	for (int i = 0; i < sz(vypos) ; i++)
		res.pb(fun(vypos[i].first, vypos[i].second, tot));
	for (int i = 0; i < sz(vxneg) ; i++)
		res.pb(fun(vxneg[i].first, vxneg[i].second, tot));
	for (int i = 0; i < sz(vyneg) ; i++)
		res.pb(fun(vyneg[i].first, vyneg[i].second, tot));
	for (int i = 0; i < sz(ru) ; i++)
		res.pb(fun(ru[i].first, ru[i].second, tot));
	for (int i = 0; i < sz(rd) ; i++)
		res.pb(fun(rd[i].first, rd[i].second, tot));
	for (int i = 0; i < sz(lu) ; i++)
		res.pb(fun(lu[i].first, lu[i].second, tot));
	for (int i = 0; i < sz(ld) ; i++)
		res.pb(fun(ld[i].first, ld[i].second, tot));

	cout<<tot<<endl;
	for(int i=0;i<sz(res);i++)
		printf("%s\n",res[i].c_str());

	return 0;
}
