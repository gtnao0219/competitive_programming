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

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,n) for(int i=a;i<n;i++)

typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

ll dp[100010][5];
vector<vector<int>> tos;
int law = 1000000000 + 7;

ll rec(int v, int w_b, int from)
{
	if (dp[v][w_b] != -1) return dp[v][w_b];
	ll res = 1;
	for (int cv : tos[v]) {
		if (cv == from) continue;
		if (!w_b) {
			res = res * ((rec(cv, 0, v) + rec(cv, 1, v)) % law) % law;
		} else {
			res = res * rec(cv, 0, v) % law;
		}
	}
	return dp[v][w_b] = res;
}

void Main()
{
	int N; cin >> N;
	rep(i,N) {
		vector<int> v;
		tos.push_back(v);
	}
	rep(i,N-1) {
		int x, y; cin >> x >> y;
		--x, --y;
		tos[x].push_back(y);
		tos[y].push_back(x);
	}
	memset(dp, -1, sizeof(dp));
	cout << ((rec(0, 0, -1) + rec(0, 1, -1)) % law) << endl;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
