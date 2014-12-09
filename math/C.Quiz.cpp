#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(v) (int)v.size()
/*
 *  the complexity of this solution is log2(n)
 *	this answer is based on this series
 *  2 6 14 30 62
 *  so we can get the index-X, will equal
 *  (2^X+1)-2
 */

ll Pow(ll x, ll n) {
    if (n == 0)
        return 1;

    if (n % 2)
        return (x*Pow( (x*x)%1000000009,n/2) %1000000009);

    return Pow( ((x * x)%1000000009), n / 2);
}


int main() {
	ll n,m,k,res=0;
	cin>>n>>m>>k;
	long long numofgroups= n/k;
	ll falseq= n-m;
	ll num = numofgroups-falseq;
	if(num>0){
		res+= (((Pow(2,num+1)-2)*k ) %1000000009); m-= num*k;
		if(res<0)
			res= 1000000009+res;
	}
	res= (res+m)%1000000009;
	cout<<res<<endl;
	return 0;
}
