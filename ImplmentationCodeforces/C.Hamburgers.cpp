	#include <bits/stdc++.h>
	using namespace std;
	#define ll 		long long
	#define mp 		make_pair
	#define sz(v) 	(int)v.size()
	#define pb    	push_back
	#define b_p(n)		__builtin_popcount(n)
	int main() {
		string s;
		int w[3]={0,0,0}, n[3], p[3];
		ll money, total = 0;
		cin >> s;
		for (int i = 0; i < 3; i++)
			scanf("%d",&n[i]);
		for (int i = 0; i < 3; i++)
			scanf("%d", &p[i]);
		cin>>money;
		for(int i=0;i<sz(s);i++)
			if(s[i]=='B')
				w[0]++;
			else if(s[i]=='S')
				w[1]++;
			else
				w[2]++;
		for(int i=0;i<3;i++)
			if(!w[i])
				n[i]=0;

		while(money>0){
			bool BB=1;
			for(int i=0;i<3;i++){
				if(n[i]<w[i]){
					int num= abs(w[i]-n[i]);
					if(money<num*p[i]){
						money=0;
						BB=0;
						break;
					}
					money-= num*p[i];
					n[i]=w[i];
				}
			}
			if(!BB)
				break;
			for(int i=0;i<3;i++)
				n[i]-=w[i];
			total++;
			bool b= n[0] | n[1] | n[2];
			if(!b)
				break;
		}

		int num=0;
		for(int i=0;i<3;i++)
			num+= p[i]*w[i];

		total+= money/num;
		cout<<total<<endl;

		return 0;
	}
