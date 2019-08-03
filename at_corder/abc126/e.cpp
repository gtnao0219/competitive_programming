#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include<iomanip>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,n) for(int i=a;i<n;i++)

typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

int X[100010];
int Y[100010];
int Z[100010];
int done[100010];
vector<int> tos[100010];

void dfs(int s)
{
	done[s] = 1;
	for (auto to : tos[s]) {
		if (!done[to]) {
			dfs(to);
		}
	}
}

void Main()
{
	int N, M; cin >> N >> M;
	rep(i,M) {
		int x, y, z; cin >> x >> y >> z;
		--x, --y;
		tos[x].push_back(y);
		if (x != y) tos[y].push_back(x);
	}
	int res = 0;
	rep(i,N) {
		if (!done[i]) {
			dfs(i);
			++res;
		}
	}
	cout << res << endl;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
}
