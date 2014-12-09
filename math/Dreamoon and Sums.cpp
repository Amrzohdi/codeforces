//============================================================================
// Name        : codeforces.cpp
// Author      : Amr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

#define ll      long long
#define mp      make_pair
#define sz(v)   (int)v.size()
#define pb      push_back
#define b_p(n)      __builtin_popcount(n)
#define MOD   1000000007

int main() {
    ios::sync_with_stdio(false);
    ll a,b;
    cin>>a>>b;

    cout<< ((((
    		(
    			(((((((b+1)+(a*b+1))%MOD)*a)%MOD)/ 2)%MOD) +
    			(((((((((b+1)+(a*b+1))%MOD)*a)%MOD)*(b-1))%MOD)/2)%MOD)
    		)*(b-1))%MOD) /2)%MOD
    	   )%MOD ;
    return 0;
}
