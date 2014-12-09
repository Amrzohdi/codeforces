#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(v) (int)v.size()

int dirx[] = { 0, 1, 0, -1 };
int diry[] = { 1, 0, -1, 0 };

bool vis[309][309];
int n, m;
bool valid(int x, int y) {
	if (x >= n || y >= m || vis[x][y])
		return false;
	if (x < 0 || y < 0)
		return false;
	return true;
}
int main() {
	memset(vis, 0, sizeof(vis));
	int k;
	cin >> n >> m >> k;
	vector<pair<int, int> > v;
	int x = 0, y = 0, dir = 0;
	while (true) {
		v.push_back(mp(x, y));
		vis[x][y] = 1;
		x += dirx[dir];
		y += diry[dir];
		int T=1;
		bool B=0;
		while (!valid(x, y) && T++) {
			x -= dirx[dir];
			y -= diry[dir];
			dir= (dir+1)%4;
			x += dirx[dir];
			y += diry[dir];

			if(T==6)
			{B=1; break;}
		}
		if(B)
			break;

	}

	int I=0,N=0;
	vector <pair<int,int> > V[k];
	int K=k;
	while(k--){
		if(k==0){
			while(I<sz(v))
				V[N].push_back(v[I++]);
			break;
		}
		V[N].push_back(v[I++]);
		V[N].push_back(v[I++]);
		N++;
	}

	for(int i=0;i<K;i++){
		printf("%d ",sz(V[i]));
		for(int x=0;x<sz(V[i]);x++)
			printf("%d %d ",V[i][x].first+1,V[i][x].second+1);
		cout<<endl;
	}
	return 0;
}
