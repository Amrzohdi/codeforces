#include <bits/stdc++.h>
using namespace std;

string arr[] = {"Druid" , "Amr" , "Momen" , "Yaseer" , "Ashraf" , "Magdy" , "Medo" , "shokry" , "Fahmy"};

int main(){
	set<int> se;
	vector<int> V;
	srand(time(0));
	while(se.size() != 9) {
		int ra = rand() % 9;
		if(se.find(ra) == se.end()) {
			V.push_back(ra);
			se.insert(ra);
		}
	}

	for(int i = 0 ; i < (int)V.size() ; i += 3)
		cout << setw(8) << left << arr[V[i]] << setw(8) << left << arr[V[i + 1]] << setw(8) << left << arr[V[i + 2]] << endl;

	return 0;
}
