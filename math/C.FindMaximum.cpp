#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(v) (int)v.size()
int ar[100009];
int main(){
	int n;

	cin>>n;
	vector <int> v(n);

	for(int i=0;i<n;i++)
		scanf("%d",&v[i]);
	string s;
	cin>>s;
	int total=v[0];
	for(int i=1;i<n;i++)
		ar[i]=total ,total+=v[i];

	int t=0;
	for(int i=0;i<n;i++)
		t+= (s[i]-'0')*v[i];
	total=0;
	for(int i=n-1;i>=0;i--){
		if(s[i]-'0')
			t=max(t, ar[i]+total);
		total+= (s[i]-'0')*v[i];
	}

	cout<<t<<endl;
	return 0;
}
