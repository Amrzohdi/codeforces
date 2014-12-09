#include <bits/stdc++.h>
using namespace std;

int arr[100001];
bool Ar[100001] = { 0 };
int n;
bool check(int ind) {
	arr[arr[ind]] = n - ind + 1;
	if (arr[ind] == 1)
			return 1;

	if (Ar[n - ind + 1]) {
		return 0;
	}

	Ar[n - ind + 1] = 1;


	check(arr[ind]);
}

int main() {
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}

	if (n % 2)
		Ar[n / 2 + 1] = 1;

	if (Ar[2]) {
		cout << -1 << endl;
		return 0;
	}

	Ar[2] = 1;
	arr[1] = 2;

	if (!check(1)) {
		cout << -1 << endl;
		return 0;
	}

	if (n % 2)
		arr[n / 2 + 1] = n / 2 + 1;

	for(int i = 1 ; i <= n ; ++i)
		if(!arr[i]) {
			cout << -1 << endl;
			return 0;
		}

	for (int i = 1; i <= n; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
