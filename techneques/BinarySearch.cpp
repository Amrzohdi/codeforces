#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)


long long int greatestNumnbersmallerthanX(vector<long long int> &v,
	    long long int target) {
	    long long int f = 0, e = v.size() - 1;
	    long long int res = -1;
	    while (f <= e) {
	        if (v[(f + e) / 2] >= target) {
	            e = (f + e) / 2 - 1;
	        } else if (v[(f + e) / 2] < target) {
	            f = (f + e) / 2 + 1;
	            res = f - 1;
	        }
	    }

	    if (res != -1)
	        return res;
	    return e;
	}


int GreatestNumbersmallerORequalX(vector <long long> U,long long target){
	long long f=0,l=sz(U)-1;
	while(f<l ){
		long long mid= (f + l)/2 ;
		if(l-f==1){
			if(U[l]>target)
				return f;
			return l;
		}
		if(mid==sz(U))
			return sz(U)-1;
		if(U[mid]==target)
			return mid;
		if(U[mid]>target)
			l=mid-1;
		else if(U[mid]<target)
			f= mid;
	}
	return l;
}


int main(){

	vector <long long> v(10);
	for(int i=0;i<10;i++){
			v[i]=i;
	}
	cout<<GreatestNumbersmallerORequalX(v,-1)<<endl;
	cout<<greatestNumnbersmallerthanX(v,5)<<endl;
	cout<<*lower_bound(v.begin(),v.end(),3)<<endl;



	return 0;
}
