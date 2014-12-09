#include <bits/stdc++.h>
using namespace std;

int ar1[] = { 1, 0, 1, -1, 1, -1, 0, -1 };
int ar2[] = { 0, 1, -1, 1, 1, -1, -1, 0 };
int Sqrt(int S){
	int res=0;
	for(int i=1;i*i<=S;i++){
		res=i;
	}
	return res;

}
int main() {
	int NN;
	cin >> NN;
	while (NN--) {
		int x, y;
		cin >> x >> y;
		int S = y - x ;
		int num = Sqrt(S);
		if(S==0){
			cout<<0<<endl;
			continue;
		}
		int total = num * 2 - 1;
		int Z = S - (num * num);

		while (Z) {
			total += Z / num;
			Z %= num;
			num--;
		}

		cout << total << endl;
	}
	return 0;
}


