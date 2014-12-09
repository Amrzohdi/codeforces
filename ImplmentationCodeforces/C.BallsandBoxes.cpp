#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
int main() {
	ios::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	int idxmin ;
	int num = -1;
	x--;
	for (int i = 0; i < n; i++){
		cin >> v[i];
		if(i==0 || num>v[i])
			num=v[i],idxmin=i;
		int dis1= (x>=i)? x-i:n-(i-x);
		int dis2= (x>=idxmin)?x-idxmin:n-(x-idxmin);
		if(num==v[i] && dis2>dis1)
			num=v[i],idxmin=i;
	}

	ll tot = 0;

	for (int i = 0; i < n; i++)
		tot += num, v[i] -= num;


	if (x != idxmin) {
		int i = (idxmin + 1) % n;
		while (i != x) {
			tot++;
			v[i]--;
			i++;
			i %= n;
		}

		if (i == x)
			v[i]--, tot++;
	}
	for (int i = 0; i < n; i++)
		if (idxmin != i)
			cout << v[i] << " ";
		else
			cout << tot << " ";
	cout << endl;
	return 0;
}
