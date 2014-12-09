#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(v) (int)v.size()
int main(){
	int n;
	cin>>n;
	vector <int>v(n);
	for(int i=0;i<n;i++)
		scanf("%d",&v[i]);
	int ar[n];
	ar[0]=v[0];
	for(int i=1;i<n;i++)
		ar[i]= ar[i-1]+v[i];

	int a=n,b=0;
	int time=0;

	for(int i=n-1;i>=0;i--){
		time+=v[i];
		if(time<ar[i]){
			b++;
			a--;
		}
		else
			break;
	}
	cout<<a<<" "<<b<<endl;
	return 0;
}
