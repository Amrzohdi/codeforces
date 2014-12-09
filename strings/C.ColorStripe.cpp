#include <bits/stdc++.h>
using namespace std;
#define ll      long long
#define mp      make_pair
#define sz(v)   (int)v.size()
#define pb      push_back

int fun(string &ss, string s, int k) {

	int T = 0;

	for (int i = 1; i < sz(s) ; i++) {
		bool b = 0;
		if (i + 1 < sz(s) && s[i + 1] == s[i] && s[i] == ss[i - 1]) {
			for (int x = 0; x < k; x++)
				if (x != s[i] - 'A') {
					ss += (char) (x + 'A');
					b = 1;
					break;
				}
			T++;
		}

		else if (s[i] == ss[i - 1]) {
			T++;
			char z = s[i];
			if (i + 1 < sz(s))
				z = s[i + 1];

			for (int x = 0; x < k; x++) {
				if (x != s[i] - 'A' && x != z - 'A') {
					ss += (char) (x + 'A');
					b = 1;
					break;
				}
			}
		} else
			ss += s[i], b = 1;

		if (!b)
			T += 9999999;
	}
	return T;
}

void Fun(string s){
	string ss,ss1;
	int x=0;
	for(int i=0;i<sz(s);i++){
		ss+= (char)(x+'A');
		ss1+= (char)( (x+1)%2+'A');
		x= (x+1)%2;
	}

	int t1=0,t2=0;
	for(int i=0;i<sz(s);i++)
		if(s[i]!=ss[i])
			t1++;
		else if(s[i]!=ss1[i])
			t2++;
	if(t1<t2){
		cout<<t1<<endl;
		cout<<ss<<endl;
		return;
	}

	cout<<t2<<endl<<ss1<<endl;
	return ;
}
int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	if(k==2){
		Fun(s);
		return 0;
	}
	int tot = 0;
	string tot1;
	for (int i = 0; i < k; i++) {
		int res = 0;
		string ss;
		ss += (char) ('A' + i);
		if (ss[0] != s[0])
			res++;
		res += fun(ss, s, k);

		if (i == 0 || res < tot) {
			tot1 = ss;
			tot = res;
		}
	}

	cout << tot << endl;
	cout << tot1;
	return 0;
}


