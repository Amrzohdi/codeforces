#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(long long)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)


ll Pow(ll base, ll pow) {
	pow%=1000000007;
	if (pow == 0)
		return 1;
	if (pow % 2)
		return (base * (Pow( (base * base)%1000000007, pow / 2)%1000000007))%1000000007;
	else
		return Pow( (base * base)%1000000007, pow / 2);
}
int main() {
	string s;
	long long int t = 0;
	cin >> s;
	ll a;
	cin >> a;
	ll r= Pow(2,sz(s))%1000000007 , Z= Pow(2,sz(s)*a)%1000000007 ;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '0' || s[i] == '5') {
			ll f=Pow(2,i);
			t= ( (f*  ( (1-Z)/(1-r) ) %1000000007 )%1000000007 + t)%1000000007;
		}
	}
	cout << t;

}
