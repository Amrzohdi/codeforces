#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
#define mod    1000000007


/*
 * it was going to be t+=  nCi . which is equals to t+= n!/ (n-i)! * i!
 * but we cant do this cuz we have taken mod from both  n! , (n-i)! , i!
 * there is a theory, because we have taken mod for them and the mod is equals to prime number
 * so we can calculate as following  n! * pow((n-i)! * i!,mod-2);
 */
int fact[1000009];
void fill(){
	fact[0]=1;
	for(ll i=1;i<1000001;i++){
		ll x= fact[i-1];
		fact[i]=  (x*i)%mod;
	}
}
bool yes(int a,int b,int x){
	while(x){
		if(x%10!=a &&x%10!=b)
			return false;
		x/=10;
	}
	return true;
}

ll Pow(ll base, ll pow) {
	if (pow == 0)
		return 1;
	if (pow % 2)
		return  (base * Pow( (base * base)%mod, pow / 2) ) % mod;
	else
		return Pow( (base * base)%mod, pow / 2);
}


int main(){
	ios::sync_with_stdio(false);
	int a,b,n;
	cin>>a>>b>>n;
	fill();

	ll t=0;
	for(int i=0;i<=n;i++){
		ll x= fact[n], y= ((ll)fact[i]*(ll)fact[n-i]) % mod;
		if(yes(a,b, i*a + b*(n-i) )){

			int res=Pow(y,mod-2);
			t= (t+ (res*x)%mod) %mod;
		}
	}

	cout<<t<<endl;
	return 0;
}
