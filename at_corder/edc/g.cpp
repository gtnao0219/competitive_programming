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

vector<vector<int>> tos;
ll dp[100010];

ll rec(int s)
{
	if (dp[s] != -1) {
		return dp[s];
	}
	ll res = 0;
	for (auto to : tos[s]) {
		res = max(res, rec(to) + 1);
	}
	return dp[s] = res;
}

void Main()
{
	int N, M; cin >> N >> M;
	rep(i,N) {
		vector<int> v;
		tos.push_back(v);
	}
	rep(i,M) {
		int x, y; cin >> x >> y;
		--x; --y;
		tos[x].push_back(y);
	}
	memset(dp, -1, sizeof(dp));
	rep(i,N) {
		if (dp[i] == -1) {
			rec(i);
		}
	}
	ll res = 0;
	rep(i,N) {
		chmax(res, dp[i]);
	}
	cout << res << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
