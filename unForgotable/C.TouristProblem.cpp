#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(v) (int)v.size()

/*
 *
 *
 */
ll gcd(ll m, ll n)
{
    if(n == 0) return m;
    return gcd(n, m % n);
}
int main(){


	int n;
	cin>>n;

	ll res=0;
	ll tota=0;

	vector <int> v(n);
	for(int i=0;i<n;i++)
		scanf("%d",&v[i]),res+= v[i];

	sort(v.begin(),v.end());

	for(int i=1;i<n;i++)
		tota+= (ll)((v[i]-v[i-1])* (ll)((ll)(i)*(ll)(n-i)));

	res+= 2*tota;
	tota= gcd(res,n);
	cout<<res/tota<<" "<<n/tota<<endl;
	return 0;
}
