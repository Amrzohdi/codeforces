#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(v) (int)v.size()

int last[1000009], first[1000009];


int main() {

    long long  p1 = 0, p2 = 0, ones = 0, k;
    long long total = 0;
    string s;
    cin >> k >> s;
    if (k == 0) {
        long long tt = 0, rres = 0;
        for (int i = 0; i < sz(s) ; i++) {
            if (s[i] == '0')
                tt++;
            else {
                rres += ((tt + 1) * tt) / 2;
                tt = 0;
            }
        }

        rres += ((tt + 1) * tt) / 2;
        cout << rres << endl;
        return 0;
    }

    {
        int p = -1;
        for (int i = 0; i < sz(s) ; i++) {
            if (s[i] == '1')
                p = i;
            last[i] = p;
        }
    }
    {
        int p = -1;

        for (int i = sz(s) - 1; i >= 0; i--) {
            if (s[i] == '1')
                p = i;
            first[i] = p;
        }
    }

    while (p2 < sz(s) ) {
        ones += s[p2] - '0';
        if (ones > k) {
            int f0 = first[p1], f1 = last[p2 - 1]; //

            long long num = (p2 - f1) * (f0 - p1 + 1);
            if (num != 0)
                total += num;

            p1 = first[p1] + 1;
            ones--;

        }
        p2++;
    }

    if (ones == k && p1 < p2) {
        int f0 = first[p1], f1 = last[p2 - 1];
        long long num = (p2 - f1) * (f0 - p1 + 1);
        total += num;
    }

    cout << total << endl;
    return 0;
}
