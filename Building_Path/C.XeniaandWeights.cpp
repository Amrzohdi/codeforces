#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back

string s;

short dp[1001][11][12];
bool fun(int m, int def, int pre) {

	if (m == 0)
		return true;

	short &B = dp[m][def][pre];

	if (B != -1)
		return B;

	B = 0;
	for (int i = 0; i < sz(s) ; i++) {
		if (i != pre && i + 1 > def && s[i] == '1') {
			B |= fun(m - 1, i + 1 - def, i);
			if(B)
				return 1;
		}
	}

	return B;
}

void BUILD(int m, int def, int pre) {

	if (m == 0) {
		return;
	}

	for(int i=0;i<10;i++){
		if(s[i]=='1' && i+1 >def && i!=pre){
			if(fun(m-1,i+1-def,i)){
				cout<<i+1<<" ";
				BUILD(m-1,i+1-def,i);
				break;
			}
		}
	}
	return ;
}
int main() {
	memset(dp, -1, sizeof(dp));
	int m;
	cin >> s >> m;

	bool B = 0;
	B |= fun(m, 0, 10);
	if (!B)
		cout << "NO\n";
	else {
		cout << "YES\n";
		BUILD(m, 0, 10);
	}
	return 0;
}
