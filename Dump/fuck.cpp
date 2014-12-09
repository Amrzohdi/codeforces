#include <bits/stdc++.h>
using namespace std;

bool willTake(long long x) {
	stringstream ss;
	ss << x;
	return ss.str()[0] <= ss.str()[ss.str().size() - 1];
}

long long removeRt(long long x) {
	return x / 10;
}

long long removeLft(long long x) {
	stringstream ss;
	ss << x;
	string temp = ss.str();
	temp = temp.substr(1);
	stringstream convert(temp);
	long long y = 0;
	convert >> y;
	return y;
}

long long makeZero(long long x) {
	stringstream ss;
	ss << x;
	string temp = ss.str();
	for (int i = 1; i < (int) temp.size(); ++i)
		temp[i] = '0';

	stringstream convert(temp);
	long long y;

	convert >> y;
	return y;
}

long long insertZero(long long x) {
	int y = x % 10;
	x /= 10;
	x *= 100;
	x += y;
	return x;
}

long long count(long long final) {
	long long res = 0;
	if (final > 10) {
		res += removeLft(removeRt(final)) + willTake(final);
		final = makeZero(final);
	}

	for (int i = 0; i < 10 && i <= final; ++i) {
		++res;
	}

	for (int i = 1; i < 10; ++i) {
		long long y = i * 11, ten = 1;
		for (int j = 0; j < 18; ++j) {
			if (y > final)
				break;
			res += ten;
			ten *= 10;
			y = insertZero(y);
		}
	}

	return res;
}

string convert(long long x) {
	stringstream ss;
	ss << x;
	string s;
	ss >> s;
	return s;
}

long long convert1(string s) {
	for (int i = 1; i < s.size(); i++)
		s[i] = '0';
	long long int T;
	stringstream ss;
	ss << s;
	ss >> T;
	return T;
}
long long taking(long long & x) {
	string s = convert(x);
	long long int res = 0;
	if (s.size() == 1) {
		return 1;
	}
	if (s[0] <= s[s.size() - 1]) {
		string S = s.substr(1, s.size() - 2);
		stringstream ss;
		ss << S;
		ss >> res;
		res++;
	} else if (s[0] > s[s.size() - 1]) {
		string S = s.substr(1, s.size() - 2);
		stringstream ss;
		ss << S;
		ss >> res;
	}
	x = convert1(s);
	return res;
}

int sizofint(long long int x) {
	int res = 0;
	while (x /= 10)
		res++;
	return res;
}

long long Pow(int x) {
	long long int res = 1;
	while (x > 0) {
		res *= 10;
		x--;
	}
	return res;
}

long long FF(long long y) {
	if (y == 1)
		return 1;
	long long int res = 10;
	for (int i = 0; i < y - 2; i++) {
		res += Pow(i) * 9;
	}
	return res;

}
long long result(long long x) {
	long long res = taking(x);
	string s = convert(x);
	long long int T = s[0] - '1';
	res += T * Pow(s.size() - 2);
	s[0] = '1';
//	cout<<res<<" "<<s<<endl;
	res += FF(s.size());
	return res;
}

bool FFun(long long int x) {
	stringstream ss;
	ss << x;
	string s;
	ss >> s;
	if (s[0] == s[s.size() - 1])
		return true;
	return false;
}
long long int Return(long long int T) {
	long long res = 0;
	for (long long int i = 0; i <= T; i++)
		if (FFun(i)) {
//			cout<<i<< endl;
			res++;
		}
	return res;
}
int main() {

	long long int x, y;

	for (x = 1; x < 100009; x++) {

		for (y = 1 + x; y <= 999999; y++) {
			if(	(count(y) - count(x - 1))
					!= (result(y) - result(x - 1) ) )
					cout<<"NIO\n";
//			cout<<(result(y) - result(x - 1)) <<endl;
		}
	}
	return 0;
}

