#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define sz(v) 	(int)v.size()
#define pb    	push_back
#define b_p(n)		__builtin_popcount(n)
int main() {
	ios::sync_with_stdio(false);
	int n, oh, wow;
	cin >> n >> oh >> wow;
	n--;
	if (n < oh + wow) {
		cout << -1 << endl;
		return 0;
	}

	vector<int> v;
	v.pb(1);
	int cum=1;
	int t=0;
	while(t++<wow)
		v.pb(cum*2),cum*=2;
	t=0;
	while(t++<oh)
		v.pb(++cum);
	t= n-wow-oh;
	while(t--)
		v.pb(cum);

	if(cum>50000)
		cout<<-1<<endl;
	else{
		if(wow==0 && oh>0){
			n--;
			if(n<oh)
				cout<<-1<<endl;
			else{
				cout<<"1 1 ";
				cum=1;
				int O=oh;
				while(oh--)
					cout<<++cum<<" ";
				n-=O;
				while(n--)
					cout<<cum<<" ";
			}
		}
		else{
		for(int i=0;i<sz(v);i++)
			cout<<v[i]<<" ";
		}
	}
	return 0;
}
