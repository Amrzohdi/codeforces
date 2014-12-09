#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	int numofzeros=0,current=0;
	for(int i=0;i<sz(s);i++)
		numofzeros+= (s[i]=='0')?1:0;
	int t=1,num=0;
	for(int i=sz(s)-1;i>=0;i--){
		if(s[i]!='0'){
			int num1=i-1;
			if(num1>num || (num1>=num&&s[i]<s[0])){
				t++;
				num=0;
			}
			else if(num1==num && s[i]==s[0]){
				num1=numofzeros-current;
				if(num1<=num){
					t++;
					num=0;
				}
				else {
					break;
				}
			}
			else{
				break;
			}
		}
		else
			num++,current++;
	}

	cout<<t<<endl;
	return 0;
}
