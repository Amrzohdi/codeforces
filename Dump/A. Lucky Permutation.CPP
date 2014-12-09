#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int main() {
	int n;
	cin >> n;
	int pat = 2, i = 1;
	bool Ar[100001] = { 0 };
	Ar[2] = 1;
	arr[1] = 2;

	while (true) {
		if (Ar[n - i + 1]) {
			cout << -1 << endl;
			return 0;
		}

		arr[arr[i]] = n - i + 1;
		Ar[n - i + 1] = 1;
		i = n - i + 1;
	}

	for (int i = 1; i <= n; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
